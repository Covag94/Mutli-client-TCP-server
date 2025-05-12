#include "../include/server.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <thread>

Server::Server(int port) : m_port(port), m_socketDescr(-1)
{}

void Server::start() {
    setUpSocket();

    while (true) {
        sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);

        std::cout << "Waiting for client to connect..." << std::endl;
        int clientSocket = accept(m_socketDescr, (struct sockaddr*)&clientAddr, &clientLen);
        if (clientSocket < 0) {
            perror("Accept failed");
            continue;
        }

        std::cout << "New client connected!" << std::endl;

        std::thread(&Server::handleClient, this, clientSocket).detach();
    }
}

void Server::setUpSocket() {
    // First prepare socket by creating the socket/file descriptor
    // AF_INET: IPv4 IP
    m_socketDescr = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketDescr < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "New socket is created" << std::endl;

    // Secondly bind to port and address
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(m_port);

    if (bind(m_socketDescr, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections on created socket
    // At most 5(backlog) number of connections can wait in queue
    // Any more connections than 5 will be dropped
    if (listen(m_socketDescr, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << m_port << std::endl;
}

void Server::handleClient(int clientSocket) {
    char buffer[1024];

    while (true) {
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));
        if (bytesRead <= 0) {
            std::cout << "Client disconnected." << std::endl;
            break;
        }

        ssize_t bytesSent = write(clientSocket, buffer, bytesRead);
        if (bytesSent < 0) {
            perror("Write failed");
            break;
        }
    }

    close(clientSocket);
}