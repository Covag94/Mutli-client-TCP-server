#pragma once
#include "socket.hpp"

class ClientHandler;

class Server
{
public:
    Server(int port, ClientHandler *handler);
    void start();

private:
    void setUpSocket();

private:
    int m_port;
    Socket m_socket;
    ClientHandler *m_handler;
};