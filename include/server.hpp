#pragma once

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
    int m_socketDescr;
    ClientHandler *m_handler;
};