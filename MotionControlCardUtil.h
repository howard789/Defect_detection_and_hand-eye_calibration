#pragma once
#include "stdafx.h"
#include "Doc.h"
#include <map>
# include "myStruct.h"

#include "../include/DMC2410.h"
#pragma comment(lib,"../lib/x64/DMC2410.lib")

#define _MotionControlCardUtil_HighSpeed 3200
#define _MotionControlCardUtil_LowSpeed 1600

#define _UP_PULSE_STD  60010              
#define _DOWN_PULSE_STD  3730 

#define _X_ZERO_POINT 21243       //X 轴原点 9眼标定
#define _Y_ZERO_POINT 39991       //Y 轴原点 9眼标定

#define _Z_ZERO_POINT 60010       //Z 轴原点 9眼标定
#define _Z_INHALE_POINT -6392       //Z 轴吸气点


#define _U_PULSE_START 63895 
#define _U_PULSE_END 70525
#define _U_ZERO_POINT ((_U_PULSE_START+_U_PULSE_END)/2)  //U 轴原点


using std::map;
class MotionControlCardUtil
{
public:
	MotionControlCardUtil();
	~MotionControlCardUtil();
    //位置清零
	void setCurrentPositionZero();

	//到达指定位置
	void moveToPoint(CPoint cp);
	void moveToPoint(int axis, int pulse);


	//移动->放下->吸气->抬起->移动->放下->放气
	void grabToLocation(CPoint cp1, CPoint cp2, int angle);
  
	void inHole();//吸气
	void gassing();//放气

	//连续运动
	void moveContinue(char axis,bool positiveDirection);
	void stopContinueMove(char axis);

	//回原点
	void moveToBasePoint(int axis);//not work？
	void moveToBaseCPoint();//二轴归零
	void moveToBaseCPointAll();//四轴归零
	void moveToBasePointCS();//回到非原点？
	void moveToBaesZ();//z轴回零
	void moveToInHolePoint();//z轴到吸气位置


	//紧急停止
	void emergentStop();

	//设定回零方式
	void setHomeMode_Speed(bool highSpeed);
	void setHomeMode_Side(bool positive);
	//check 回零方式
	bool isHomeMode_HighSpeed();
	bool isHomeMode_PositiveSide();

	//设定运动方式
	void setMovingMode_S();//匀速
	void setMovingMode_T();//变速 如果运行速度=开始速度，则运行速度=2*开始速度
	
	//设定运动速度
	void setHighSpeed();
	void setLowSpeed();



	//取得当前位置状态
	CPoint getCurrentPosition();
	CPoint getBasePosition();
	int getCurrentPulse(char aixs);
	bool isHighSpeedMode();
	bool isMoveMode_S();
	bool isStop(char axis);
	bool isAllStop();
	bool isSymmetry();
	CString getStatus(bool allAxis,char axis);
    double readCurrentSpeed(int m_nAxis);
    double readCurrentSpeedMax();
	int readSpeedStart();
	int readSpeedMax();
	double readAccl();//加速时间


	HWND hWnd;//提示初始化板卡失败用的

	//CPoint *nextTarget;

	int angleDegreeToPulse(double degree);//角度转脉冲数


private:

	void up(bool zeroUAxis);
	void down(bool inhole, bool gassing, bool inhole2, bool gassing2);


	void Move();//除了回零，所有运动都要调用这个，不可以直接调用厂商提供的接口
	void OnCheckSymmetry(bool isSymmetry);
	void moveToAxisPoint(int axis, int pulse);//单轴运动

	//停止的通用接口
	void Stop(bool isEmerge, bool oneAxis, int axis);



	int BoardInit();
	void OnDestroy();
	
	int boardsNum;
	BOOL	m_bLogic;//逻辑方向 正/反
	BOOL	m_bSymmetry;//对称

	double	m_fAccel;//加速时间
	double	m_fDecel;//减速时间
    double	m_nTSacc;//S段时间
	
	long	m_nPulse;//移动的点位长度
	
	
	long	m_nStopVel;// 停止速度
	long	m_nSpeedmax;//运行速度
	long	m_nSpeedst;//起始速度

	int		m_nActionst;// 0 点动, 1 持续运动

	int		m_nCmove;//持续

	int	 m_nAxis; //运动轴选择 0-3

	
	int		m_nHome;//回零方式
	int		m_nEzno;//回零方式
	bool m_HomeMode_HighSpeed;//回零高速
	bool m_HomeMode_Positive;//回零 正向

	bool moveMode_S; //S型运动（平滑匀速）
	bool highSpeedMode;//高速运动

	bool successInit;//初始化成功
	int direction;//运动方向，正向为1 负向为0

	
};

