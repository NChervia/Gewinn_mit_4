#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>


class Client
{
private:

    //variables
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ConnectSocket = INVALID_SOCKET;

    //Function
    int initSocket();
 

public:
    Client();
    ~Client();

    void ClientStart();
    void ClientOut();

    int readServer();

    void sendToServer(int buffer);
};


