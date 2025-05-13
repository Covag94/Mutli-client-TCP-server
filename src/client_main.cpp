#include "../include/socket.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    Socket clientSocket = Socket(socket(AF_INET, SOCK_STREAM, 0));
    if (clientSocket.get() < 0)
    {
        perror("Socket creation failed");
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    // Need to translate 127.0.0.1 str to actual address
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address / Adress not supported\n";
        return 1;
    }

    // Socket needs to be connected to specified address
    if (connect(clientSocket.get(), (sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Connection failed");
        return 1;
    }

    std::cout << "Connected to server. Type something to send\n";

    char buffer[1024];
    while (std::cin.getline(buffer, sizeof(buffer)))
    {
        ssize_t sent = send(clientSocket.get(), buffer, strlen(buffer), 0);
        if (sent < 0)
        {
            perror("Send failed");
            break;
        }

        char reply[1024];
        ssize_t received = recv(clientSocket.get(), reply, sizeof(reply) - 1, 0);
        if (received <= 0)
        {
            std::cout << "Server closed connection.\n";
            break;
        }

        reply[received] = '\0';
        std::cout << "Echo from server : " << reply << std::endl;
    }
}