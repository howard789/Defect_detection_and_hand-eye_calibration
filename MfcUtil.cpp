#include "MfcUtil.h"

MfcUtil::MfcUtil()
{
}


MfcUtil::~MfcUtil()
{
}

string MfcUtil::intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

string MfcUtil::doubleToString(double value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}


void MfcUtil::ShowPic(CString filePath, WORD mfcID)//形参可以为所给的图片对象的指针，这里为了通用性省去了形参
{
	
	//在mfcID显示图片，调整大小维持比例
	float cx, cy, dx, dy, k, t;//跟控件的宽和高以及图片宽和高有关的参数
	CRect   rect;//用于获取图片控件的宽和高
	CImage q;//为cimage图片类创建一个对象
	q.Load(filePath);//构造函数的形参是所加载图片的路径 
	cx = q.GetWidth();
	cy = q.GetHeight();//获取图片的宽 高
	k = cy / cx;//获得图片的宽高比

	CWnd *pWnd = NULL;
	pWnd = GetDlgItem(mfcID);//获取控件句柄
	pWnd->GetClientRect(&rect);//获取Picture Control控件的客户区
	dx = rect.Width();
	dy = rect.Height();//获得控件的宽高比
	t = dy / dx;//获得控件的宽高比
	if (k >= t)
	{

		rect.right = floor(rect.bottom / k);
		rect.left = (dx - rect.right) / 2;
		rect.right = floor(rect.bottom / k) + (dx - rect.right) / 2;
	}
	else
	{
		rect.bottom = floor(k*rect.right);
		rect.top = (dy - rect.bottom) / 2;
		rect.bottom = floor(k*rect.right) + (dy - rect.bottom) / 2;
	}
	//相关的计算为了让图片在绘图区居中按比例显示，原理很好懂，如果图片很宽但是不高，就上下留有空白区；如果图片很高而不宽就左右留有空白区，并且保持两边空白区一样大

	CDC *pDc = NULL;
	pDc = pWnd->GetDC();//获取picture control的DC，这是什么玩意我也不知道，百度就行
	int ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);//设置指定设备环境中的位图拉伸模式

	GetDlgItem(mfcID)->ShowWindow(FALSE);
	GetDlgItem(mfcID)->ShowWindow(TRUE);
	q.StretchBlt(pDc->m_hDC, rect, SRCCOPY);//显示函数
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	//ReleaseDC(mfcID);//释放指针空间
}

//UTF8转Unicode
CString MfcUtil::UTF82WCS(const char* szU8)
{
	//预转换，得到所需空间的大小;
	int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);

	//分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
	wchar_t* wszString = new wchar_t[wcsLen + 1];

	//转换
	::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);

	//最后加上'\0'
	wszString[wcsLen] = '\0';

	CString unicodeString(wszString);

	delete[] wszString;
	wszString = NULL;

	return unicodeString;
}

double MfcUtil::CStringToDouble(CString cstr)
{
	char * ch = CStringToChar(cstr);
	return atof(ch);
}

int MfcUtil::CStringToInt(CString str)
{
	return _ttoi(str);
}

int MfcUtil::stringToInt(string str)
{
	return atoi(str.c_str());
}

CString MfcUtil::charToCString(char * chString)
{
	return CString(chString);
}

LPWSTR MfcUtil::charToLPWSTR(char * ch)
{
	LPWSTR aaa = CA2W(ch);
	return aaa;
}

CString MfcUtil::DoubleToCString(double value,int digital)
{
	CString str;

	if (digital == 0) 
	{
		str.Format(_T("%.0lf"), value);//0位数
	}
	else
	{
		str.Format(_T("%.2lf"), value);//2位数
	}
	return str;
}


char * MfcUtil::CStringToChar(CString cstr)
{
	//声明标识
	USES_CONVERSION;
	//函数T2A和W2A均支持ATL和MFC中的字符
	//char * pFileName = T2A(cstr);
	char * pFileName = W2A(cstr); //也可实现转换
	return pFileName;
}

CString MfcUtil::CharToCString(char * pFileName)
{
	//计算char *数组大小，以字节为单位，一个汉字占两个字节
	int charLen = strlen(pFileName);
	
	//计算多字节字符的大小，按字符计算。
	int len = MultiByteToWideChar(CP_ACP, 0, pFileName, charLen, NULL, 0);

	//为宽字节字符数组申请空间，数组大小为按字节计算的多字节字符大小
	TCHAR *buf = new TCHAR[len + 1];
	
	//多字节编码转换成宽字节编码
	MultiByteToWideChar(CP_ACP, 0, pFileName, charLen, buf, len);
	
	buf[len] = '/0'; //添加字符串结尾，注意不是len+1
	
	//将TCHAR数组转换为CString
	CString pWideChar;
	pWideChar.Append(buf);
	
		//删除缓冲区
	delete[]buf;
	return pWideChar;
}

string MfcUtil::CStringToString(CString str)
{
	char* c = CStringToChar(str);

	return c;
}

LPCTSTR MfcUtil::charToLPCTSTR(char * ch)
{
	//char ch[1024] = "wo shi ni baba";
	int num = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);
	wchar_t *wide = new wchar_t[num];
	MultiByteToWideChar(0, 0, ch, -1, wide, num);
	return wide;
}

char* MfcUtil::LPCTSTRToChar(LPCTSTR widestr)
{
	//wchar_t widestr[1024] = L"wo shi ni yeye";
	int num = WideCharToMultiByte(CP_OEMCP, NULL, widestr, -1, NULL, 0, NULL, FALSE);
	char *pchar = new char[num];
	WideCharToMultiByte(CP_OEMCP, NULL, widestr, -1, pchar, num, NULL, FALSE);
	return pchar;
}

string MfcUtil::IntToString(int value, int modeDigital)
{

	// value：欲转换的数据。
		 // string：目标字符串的地址。
	// radix：转换后的进制数，可以是10进制、16进制等。
	 // 返回指向string这个字符串的指针
	char * chr=new char[100];
	_itoa_s(value,chr,100,modeDigital);
	//string str = chr;
	return chr;

}


LPCTSTR MfcUtil::StringToLPCSTR(string value) {

	LPCWSTR  * unicodeLPCTSTR = nullptr;
	LPCSTR * unLPCTSTR=nullptr;
	StringToLPCSTR(value, unicodeLPCTSTR, unLPCTSTR);
#ifdef _UNICODE
	return *unicodeLPCTSTR;
#else
	return *unLPCTSTR;
#endif
}

LPCWSTR MfcUtil::charToLPCWSTR(char * cString)
{


	return CStringToLPCWSTR(CString(cString));
}

LPCWSTR MfcUtil::CStringToLPCWSTR(CString str)
{

	//USES_CONVERSION;
	//LPCWSTR wszClassName = new WCHAR[str.GetLength() + 1];
	//wcscpy((LPTSTR)wszClassName, T2W((LPTSTR)str.GetBuffer(NULL)));
	//str.ReleaseBuffer();
	//return str;



	USES_CONVERSION;
	rsize_t size = str.GetLength() + 1;
	LPCWSTR wszClassName = new WCHAR[str.GetLength() + 1];
	wcscpy_s((wchar_t*)wszClassName, size, str);
	return str;

}


LPCSTR MfcUtil::CStringToLPCSTR(CString cstr)
{
	char* chr = CStringToChar(cstr);
	return (LPCSTR)chr;
}

void MfcUtil::StringToLPCSTR(string value, LPCWSTR  * unicodeLPCTSTR, LPCSTR * unLPCTSTR)
{

#ifdef _UNICODE_hao
	size_t origsize = value.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(value.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, value.c_str(), _TRUNCATE);
	unicodeLPCTSTR = &wcstring;
#else

	LPCSTR str = value.c_str();
	unLPCTSTR = &str;
#endif

}

LPCWSTR MfcUtil::stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}


void MfcUtil::getStringFromDlg(HWND dlgID,int itemID)
{
	//CEdit* pBoxOne;
	//pBoxOne = (CEdit*)GetDlgItem(dlgID, itemID);
	////赋值
	////pBoxOne-> SetWindowText( _T("FOO ") );
	////取值
	//CString str;
	//pBoxOne->GetWindowText(str);
	//return str;
	
}

CString MfcUtil::concatCstring(char* c1, int i, char* c2)
{
	

	CString csi;
	csi.Format(_T("%d"),i);
	csi = CharToCString(c1) + csi + CharToCString(c2);
	return csi;
}

void MfcUtil::openFileBrowser(CString defaultPath, CWnd* pParentWnd, int mfcID)
{
	//将选择动档案路径显示在指定的对话框内

	LPCWSTR defaultPathW = CStringToLPCWSTR(defaultPath);

	//LPCWSTR defaultPath = defaultPath;

	SetCurrentDirectory(defaultPath);
	//static char BASED_CODE szFilter[] = "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";

	LPCTSTR lpszFilter = TEXT("*.mat|文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	
	lpszFilter = NULL;
	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, pParentWnd,0,TRUE);

	//FileDlg.m_ofn.lpstrInitialDir = defaultPath;
	FileDlg.m_ofn.lpstrInitialDir = TEXT("D:\tmp");
	CString editParam;
	if (FileDlg.DoModal() == IDOK)
	{

		CString strFileName = FileDlg.GetFileName();
		CString strFileExt = FileDlg.GetFileExt();
		CString lpstrName = FileDlg.GetPathName();
		editParam = lpstrName;
		pParentWnd->GetDlgItem(mfcID)->SetWindowTextW(editParam);
	}


	//return editParam;
}

void MfcUtil::setPictureColorRed(CWnd *pWnd, int mfcId, CStatic& m_static)
{

	setPictureColor(pWnd, mfcId, m_static, 255, 0, 0);

}

void MfcUtil::setPictureColorGreen(CWnd *pWnd,int mfcId, CStatic& m_static)
{

	setPictureColor(pWnd, mfcId, m_static,0,255,0);

}



void MfcUtil::setPictureColor(CWnd *pWnd, int mfcId, CStatic& m_static,int red,int green,int blue)
{

	CRect rc;
	CWnd *iWnd = pWnd->GetDlgItem(mfcId);//参数为控件ID
	iWnd->GetClientRect(&rc);//rc为控件的大小。
	int py = rc.Height();
	int px = rc.Width();

	FillRect(m_static.GetDC()->GetSafeHdc(), &rc, CBrush(RGB(red, green, blue)));

}

char*  MfcUtil::hexToCharIP(struct in_addr addrIP)
{  //in_addr
	char* ip;
	unsigned int intIP;
	memcpy(&intIP, &addrIP, sizeof(unsigned int));
	int a = (intIP >> 24) & 0xFF;
	int b = (intIP >> 16) & 0xFF;
	int c = (intIP >> 8) & 0xFF;
	int d = intIP & 0xFF;
	if ((ip = (char*)malloc(16 * sizeof(char))) == NULL)
	{
		return NULL;
	}
	sprintf(ip, "%d.%d.%d.%d", d, c, b, a);
	return ip;
}


void MfcUtil::Split(const string& src, const string& separator, vector<string>& dest)
{
	string str = src;
	string substring;
	string::size_type start = 0, index;
	dest.clear();
	index = str.find_first_of(separator, start);
	do
	{
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = index + separator.size();
			index = str.find(separator, start);
			if (start == string::npos) break;
		}
	} while (index != string::npos);

	//the last part
	substring = str.substr(start);
	dest.push_back(substring);
}
