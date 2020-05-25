#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<Winsock2.h>
#include<fstream>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        printf("加载套接字库版本不一致");
        return -1;
    }
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//AF_INET internet协议
    if (serverSocket == SOCKET_ERROR) {
        printf("创建协议失败");
        WSACleanup;
        return -1;
    }
    printf("创建socket成功");

    SOCKADDR_IN addr = { 0 };
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = inet_addr("192.168.31.18");
    addr.sin_port = htons();

    return 0;
}

