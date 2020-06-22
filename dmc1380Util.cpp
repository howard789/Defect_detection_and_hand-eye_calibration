#include "dmc1380Util.h"

const int XCH = 0;
const int YCH = 1;
const int ZCH = 2;
const int UCH = 3;

dmc1380Util::dmc1380Util()
{

	runThread = false;
	hWnd = AfxGetApp()->GetMainWnd()->GetSafeHwnd();

	nStart = 150; //开始速度
	nMSpeed=300;//max speed
	nTAcc=0.01;//acc time
	nPulse=2000;//定量脉冲
    nPos = 0;//特定位置

	moveMode_T = true;//T型运动
	moveModeFixPosFixDisSpeed = 2;

	lasePulseTriger = 0;
	
	boardsNum = BoardInit();
	if (boardsNum > 0) {
		successInit = true;
	}


}


dmc1380Util::~dmc1380Util()
{

	d1000_board_close();
}

int dmc1380Util::BoardInit()
{
	int i = d1000_board_init();
	if (i <= 0)//控制卡的初始化操作
	{
		MessageBox(hWnd, TEXT("初始化DMC1380卡失败！"), TEXT("出错"), NULL);
		return 0;
	}
	return i;;
}



void dmc1380Util::Move()
{
	if (!successInit)
		return;
	switch (moveModeFixPosFixDisSpeed)
	{
	case 0:

		d1000_start_ta_move(0, nPos, nStart, nMSpeed, nTAcc);
		break;
	case 1:
		d1000_start_t_move(0, nPulse, nStart, nMSpeed, nTAcc);
		break;
	case 2:

		d1000_start_tv_move(0, nStart, nMSpeed, nTAcc);
		break;
	}
}

void dmc1380Util::emergentStop()
{
	Stop(true);
}

void dmc1380Util::generalStop()
{
	Stop(false);
}

void dmc1380Util::setCurrentPositionZero()
{
	for (int i = 0; i < 4; i++)
		d1000_set_command_pos(i, 0);
}

int dmc1380Util::getCurrentPulse()
{
	return d1000_get_command_pos(0);
}

void dmc1380Util::enpowerEngine(bool enpower)
{
	if(enpower)
		d1000_out_bit(5, 1);
	else
		d1000_out_bit(5, 0);
}

void dmc1380Util::enableGassing(bool enpower)
{
	if(enpower)
		d1000_out_bit(3, 1);
	else
		d1000_out_bit(3, 0);

}



void dmc1380Util::gassing_no1(bool gassing)
{
	if(gassing)
		d1000_out_bit(2, 0);
	else
		d1000_out_bit(2, 1);
}

void dmc1380Util::gassing_no2(bool gassing)
{
	if (gassing)
		d1000_out_bit(1, 0);
	else
		d1000_out_bit(1, 1);
}

void dmc1380Util::enableVibrationPlate(bool enable)
{
	if (enable)
		d1000_out_bit(4, 1);
	else
		d1000_out_bit(4, 0);
}

bool dmc1380Util::isItemsComing()
{
	if (d1000_in_bit(1) == 0)
		return true;
	else
		return false;
}





void dmc1380Util::Stop(bool isEmerge)
{
	if (isEmerge) {
		d1000_immediate_stop(XCH);
		//d1000_immediate_stop(YCH);
		//d1000_immediate_stop(ZCH);
		//d1000_immediate_stop(UCH);
	}
	else
	{
		if (d1000_check_done(XCH) == 0 //在运行
			|| d1000_check_done(YCH) == 0
			|| d1000_check_done(ZCH) == 0
			|| d1000_check_done(UCH) == 0)
		{//当减速时间为0时，为急停效果
			d1000_decel_stop(XCH);
			//d1000_decel_stop(YCH);
			//d1000_decel_stop(ZCH);
			//d1000_decel_stop(UCH);
			return;
		}
	}

}

CString dmc1380Util::getDequesSize()
{
	CString cs;
	cs.Format(_T("camera1:%d,Ng:%d,Ok:%d"),Camera1Deque.size(), Gass1Deque.size(), Gass2Deque.size());

	return cs;
}

void dmc1380Util::dealTrigerDeque()
{//由ontimer 测到物料且启动检测的时候调用

	

		//if((getCurrentPulse() - lasePulseTriger) < 200)
		//	return;

		lasePulseTriger = getCurrentPulse();
		InfoUnit newInfo;
		
		//newInfo.cameraOnePicPulse_schedule_ = lasePulseTriger + PULSE_TRIGER_CAMERA1;
		newInfo.cameraOnePicPulse_schedule_Min = lasePulseTriger + PULSE_TRIGER_CAMERA1_MIN;
		newInfo.cameraOnePicPulse_schedule_Max = lasePulseTriger + PULSE_TRIGER_CAMERA1_MAX;
		newInfo.cameraOnePicPulse_schedule_Mid = lasePulseTriger + PULSE_TRIGER_CAMERA1;
		newInfo.ng_pulse = lasePulseTriger + PULSE_TRIGER_GassingOne;
		newInfo.ok_pulse = lasePulseTriger + PULSE_TRIGER_GassingTwo;


		newInfo.result = 0;
		newInfo.cameraOneDown = false;

		Camera1Deque.push_back(newInfo);
		//count_CameraOne++;

}



void dmc1380Util::dealGass1Deque()
{
	int lastcount = 0;
	while (runThread)
	{
		while (Gass1Deque.size() > lastcount)
		{
			InfoUnit info = Gass1Deque[lastcount];
			lastcount++;
			
		    
			while (getCurrentPulse() < info.ng_pulse);

			gassing_no1(true);
			m_count_gassing1++;
			gassing_no1(false);
		}
	}


}

void dmc1380Util::dealGass2Deque()
{
	int lastcount = 0;
	while (runThread)
	{
		while (Gass2Deque.size() > lastcount)
		{
			InfoUnit info = Gass2Deque[lastcount];
			lastcount++;
			while (getCurrentPulse() < info.ok_pulse);

			gassing_no2(true);
			m_count_gassing2++;
			gassing_no2(false);
		}
	}



}

void dmc1380Util::clearDeques()
{
	Camera1Deque.clear();
	Gass1Deque.clear();
	Gass2Deque.clear();
	
	

}

void dmc1380Util::resetCount()
{
	m_count_trigger = 0;
	m_count_ok = 0;
    m_count_ng = 0;
	m_count_camera=0;
	m_count_gassing1=0;
	m_count_gassing2=0;
}



void dmc1380Util::setResult(InfoUnit &info,bool pass,bool cameraOneDown)
{
	
	info.cameraOneDown = cameraOneDown;

	if (pass==false)
	{
		info.result = 1;
		Gass1Deque.push_back(info);
		m_count_ng++;
	}
	else
	{
		info.result = 2;
		Gass2Deque.push_back(info);
		m_count_ok++;
	}
	
}





