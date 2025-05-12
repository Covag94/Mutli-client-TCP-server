#include "../include/server.hpp"
#include "echo_handler.cpp"

int main() {
    EchoHandler handler;
    Server server(8080, &handler);
    server.start();
}