#pragma once
#include "socket.hpp"

class ClientHandler
{
public:
    virtual ~ClientHandler() = default;
    virtual void handle(Socket clientSocket) = 0;
};