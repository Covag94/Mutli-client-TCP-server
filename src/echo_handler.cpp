#include <iostream>
#include <unistd.h>
#include <cstring>
#include "../include/client_handler.hpp"
#include "../include/echo_handler.hpp"

void EchoHandler::handle(int clientSocket)
{
    char buffer[1024];
    while (true)
    {
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));
        if (bytesRead <= 0)
        {
            std::cout << "Client disconnected." << std::endl;
            break;
        }

        ssize_t bytesSent = write(clientSocket, buffer, bytesRead);
        if (bytesSent < 0)
        {
            perror("Write failed");
            break;
        }
    }

    close(clientSocket);
}
