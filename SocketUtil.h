#pragma once
#include "afxwin.h"
#include "winsock2.h"
#include "ws2tcpip.h"
#include <afxdialogex.h>
#include <iostream>

using namespace std;

class SocketUtil : public CDialogEx
{
	SocketUtil();
	~SocketUtil();

	afx_msg LRESULT OnSocket(WPARAM	w, LPARAM l);

private:
	string m_ip;
	string m_port;
	string m_SendMessage;
	char* serverName;
	char* serverPort;
	WSADATA wsaData;
	SOCKET ConnectSocket;

	void conn();
	void close();






};

