#pragma once
#include <afxwin.h>
#include <string>

using namespace std;

class MyRealButton :
	public CButton
{
public:
	
	MyRealButton(string button_id);
	~MyRealButton();
	BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT * pResult);

	string button_id;

};

