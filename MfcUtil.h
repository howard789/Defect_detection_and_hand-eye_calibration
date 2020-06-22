#pragma once
#include "stdafx.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include "atlimage.h"
#include "resource.h"
#include <atltypes.h>
#include <string>
#include <sstream>
#include <vector>


using namespace std;
class MfcUtil : public CDialog
{
public:
	MfcUtil();
	~MfcUtil();

	//General util
	static string intToString(int value);
	static string doubleToString(double value);
    static string IntToString(int i, int modeDigital);
	static LPCTSTR StringToLPCSTR(string value);
	static LPCWSTR charToLPCWSTR(char *cString);
	static LPCWSTR CStringToLPCWSTR(CString cString);

	void ShowPic(CString filePath, WORD mfcID);
	static CString UTF82WCS(const char * szU8);//utf8 转为unicode,二维码扫描用

	
	static CString DoubleToCString(double value, int digital);
	
	static char* CStringToChar(CString str);
    static double CStringToDouble(CString str);
    static int CStringToInt(CString str);
    static int stringToInt(string str);
	static CString charToCString(char * cString);

	static LPWSTR charToLPWSTR(char* ch);


	static CString CharToCString(char *c);
	static string CStringToString(CString str);

	static LPCTSTR charToLPCTSTR(char* ch);
	static char* LPCTSTRToChar(LPCTSTR str);

	
	static LPCSTR CStringToLPCSTR(CString cstr);

	static void StringToLPCSTR(string value, LPCWSTR  * unicodeLPCTSTR, LPCSTR * unLPCTSTR);

	static LPCWSTR stringToLPCWSTR(std::string orig);

	static void getStringFromDlg(HWND dlgID, int itemID);


	static CString concatCstring(char* cs1,int i,char* cs2);


	static void openFileBrowser(CString defaultPath, CWnd* pParentWnd, int mfcID);

	void setPictureColorRed(CWnd * pWnd, int mfcId, CStatic & m_static);

	void setPictureColorGreen(CWnd *pWnd, int mfcId, CStatic & m_static);

	void setPictureColor(CWnd * pWnd, int mfcId, CStatic & m_static, int red, int green, int blue);

	static char * hexToCharIP(in_addr addrIP);

	static void Split(const string & src, const string & separator, vector<string>& dest);



};

//CDlg3 *wnd = (CDlg3*)AfxGetMainWnd();
//CProjectOneDlg *pMPD = (CProjectOneDlg*)this->GetParent();