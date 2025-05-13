#pragma once

#include "client_handler.hpp"

class EchoHandler : public ClientHandler
{
public:
    void handle(int clientSocket) override;
};