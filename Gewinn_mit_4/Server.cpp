#pragma once
#define WIN32_LEAN_AND_MEAN
#include "Server.h"

int Server::initServer()
{
    /*
    *  return 1    Error WSAStartup;
    *  return 2    Error getaddrinfo;
    *  return 3    Error ConnectScocket;
    *  return 4    Error Bind;
    *  return 5    Error listen;
    */
    int retErorr = 0;

    retErorr = WSAStartup(MAKEWORD(2, 2), &this->wsaData);
    if (retErorr != 0) return 1;

    ZeroMemory(&this->hints, sizeof(this->hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    retErorr = getaddrinfo(NULL, "80", &this->hints, &this->addrResult);
    if (retErorr != 0) return 2;

    this->ListenSocket = socket(this->addrResult->ai_family, this->addrResult->ai_socktype, this->addrResult->ai_protocol);
    if (this->ListenSocket == INVALID_SOCKET) return 3;

    retErorr = bind(this->ListenSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
    if (retErorr == SOCKET_ERROR) return 4;

    retErorr = listen(this->ListenSocket, 10);
    if (retErorr == SOCKET_ERROR) return 5;

    return 0;
}

void Server::ServerStart()
{
  int result = this->initServer();
    if (result == 0)std::cout << "Server ready!" << std::endl;
    else std::cout << "Conect error!" << std::endl;
}

bool Server::addClient()
{
    this->ClientSocket = accept(this->ListenSocket, NULL, NULL);
    if (this->ClientSocket == INVALID_SOCKET)
    {
        std::cout << "Error accept" << std::endl;
        return false;
    }
    std::cout << "Client conect, Socket: " << this->ClientSocket << std::endl;
    return true;
}

void Server::ServerOut()
{
    int result = send(this->ClientSocket, "**/", 3, 0);
    if (result == SOCKET_ERROR)std::cout << "Error send " << result << std::endl;
    closesocket(this->ListenSocket);
    closesocket(this->ClientSocket);
    freeaddrinfo(this->addrResult);
    WSACleanup();
    std::cout << "The End" << std::endl;
}



Server::Server()
{
  
}

Server::~Server()
{
    
}



int Server::readClient()
{
    int result = 0;
    char Buffer[512];
    while (true)
    {
        ZeroMemory(Buffer, 512);
        result = recv(this->ClientSocket, Buffer, 512, 0);
        if (result > 0)
        {
            if ((Buffer[0] == '*') && (Buffer[1] == '*')&& (Buffer[2] != '/'))
            {
                return Buffer[2] - '1';
            }
            return 103;
        }
        else if (result == 0)
        {
            std::cout << "Connection closed" << std::endl;
            return 101;
        }
        else
        {
            std::cout << "Error recv" << std::endl;
            return 102;
        }
    }
}

void Server::sendToClient(int buffer)
{
    char bufferint[4];
    bufferint[0] = '*';
    bufferint[1] = '*';
    bufferint[2] = (buffer % 10) + '1';
    bufferint[3] = 0;
    int result = send(this->ClientSocket, bufferint, 4, 0);
    if (result == SOCKET_ERROR)std::cout << "Error send " << result << std::endl;
}
