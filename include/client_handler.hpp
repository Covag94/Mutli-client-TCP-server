#pragma once

class ClientHandler
{
public:
    virtual ~ClientHandler() = default;
    virtual void handle(int clientSocket) = 0;
};