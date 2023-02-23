#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

class Server
{

private:
    //Variables
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;

    char recvBuffer[512];

    //Functions
    int initServer();



public:
    Server();
    ~Server();

    void ServerStart();
    bool addClient();

    void readClient();

    void sendToClient(int buffer);
};

