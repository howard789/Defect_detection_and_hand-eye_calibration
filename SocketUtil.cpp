//#include "SocketUtil.h"
//
//#define DEFAULT_BUFLEN 1024
//#define WM_SOCKET WM_USER+11
//
//SocketUtil::SocketUtil()
//{
//}
//
//
//SocketUtil::~SocketUtil()
//{
//}
//
//
//bool SocketUtil::realConn()
//{
//	USES_CONVERSION;
//	serverName = T2A(m_ip.GetBuffer(0));
//	m_ip.ReleaseBuffer();
//	serverPort = T2A(m_port.GetBuffer(0));
//	m_port.ReleaseBuffer();
//	conn();
//	WSAAsyncSelect(ConnectSocket, m_hWnd, WM_SOCKET, FD_READ);
//
//
//
//
//
//}
//
//
//
//
//
//void SocketUtil::conn_impl(char* serverName, char* serverPort)
//{
//	ConnectSocket = INVALID_SOCKET;
//	struct addrinfo *ptr, *result = NULL;
//	struct addrinfo hints;
//	int iResult = 0;
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0)
//		MessageBoxA(NULL, "WSAStartup failed with error", "error", MB_OK);
//	/*hostName = new char[256];
//	gethostname(hostName,sizeof(hostName));*/
//	ZeroMemory(&hints, sizeof(hints));
//	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_protocol = IPPROTO_TCP;
//	hints.ai_flags = AI_PASSIVE;
//
//	// Resolve the server address and port
//	iResult = getaddrinfo(serverName, serverPort, &hints, &result);
//	if (0 != iResult) {
//		MessageBoxA(NULL, "getaddrinfo failed with error", "error", MB_OK);
//		WSACleanup();
//	}
//	// Attempt to connect to an address until one succeeds
//	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
//
//		// Create a SOCKET for connecting to server
//		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
//			ptr->ai_protocol);
//		if (ConnectSocket == INVALID_SOCKET) {
//
//			WSACleanup();
//		}
//
//		// Connect to server.
//		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
//		if (iResult == SOCKET_ERROR) {
//			closesocket(ConnectSocket);
//			ConnectSocket = INVALID_SOCKET;
//			continue;
//		}
//		break;
//	}
//	freeaddrinfo(result);
//
//	if (ConnectSocket == INVALID_SOCKET) {
//		MessageBoxA(NULL, "socket failed with error", "error", MB_OK);
//		WSACleanup();
//	}
//}
//
//void SocketUtil::close()
//{
//	int iResult = shutdown(ConnectSocket, SD_SEND);
//	if (iResult == SOCKET_ERROR) {
//		MessageBoxA(NULL, "shutdown failed with error", "error", MB_OK);
//		closesocket(ConnectSocket);
//		WSACleanup();
//	}
//	closesocket(ConnectSocket);
//	WSACleanup();
//}
//
