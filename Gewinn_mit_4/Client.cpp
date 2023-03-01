#include "Client.h"

int Client::initSocket()
{
    /*
    *  return 1    Error WSAStartup;
    *  return 2    Error getaddrinfo;
    *  return 3    Error ConnectScocket;
    *  return 4    Error connect;
    */
    int retErorr = 0;

    retErorr = WSAStartup(MAKEWORD(2, 2), &this->wsaData);
    if (retErorr != 0) return 1;

    ZeroMemory(&this->hints, sizeof(this->hints));
    this->hints.ai_family = AF_INET;
    this->hints.ai_socktype = SOCK_STREAM;
    this->hints.ai_protocol = IPPROTO_TCP;

    retErorr = getaddrinfo("localhost", "80", &this->hints, &this->addrResult);
    if (retErorr != 0) return 2;

    this->ConnectSocket = socket(this->addrResult->ai_family, this->addrResult->ai_socktype, this->addrResult->ai_protocol);
    if (this->ConnectSocket == INVALID_SOCKET) return 3;

    retErorr = connect(this->ConnectSocket, this->addrResult->ai_addr, (int)this->addrResult->ai_addrlen);
    if (retErorr == SOCKET_ERROR)return 4;



    return 0;
}


Client::Client()
{

}

Client::~Client()
{

    
}

void Client::ClientStart()
{
    int time = 1000;
    while (time!=0)
    {
        int result = this->initSocket();
        if (result == 0) 
        {
            std::cout << "Client ready!" << std::endl;
            return;
        }
        time--;
    }
    std::cout << "Conect error!" << std::endl;
    this->ClientOut();
}

void Client::ClientOut()
{
    closesocket(this->ConnectSocket);
    freeaddrinfo(this->addrResult);
    WSACleanup();
}


int Client::readServer()
{
    int result = 0;
    char Buffer[512];
    while (true)
    {
        ZeroMemory(Buffer, 512);
        result = recv(this->ConnectSocket, Buffer, 512, 0);
        if (result > 0)
        {
            if ((Buffer[0] == '*') && (Buffer[1] == '*') && (Buffer[2] != '/'))
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




void Client::sendToServer(int buffer)
{
    char bufferint[4];
    bufferint[0] = '*';
    bufferint[1] = '*';
    bufferint[2] = (buffer % 10) + '1';
    bufferint[3] = 0;

    int result = send(this->ConnectSocket, bufferint, 4, 0);
    if (result == SOCKET_ERROR)std::cout << "Error send " << result << std::endl;
}
