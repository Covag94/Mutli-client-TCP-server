#include "../include/server.hpp"
#include "../include/echo_handler.hpp"

int main() {
    EchoHandler handler;
    Server server(8080, &handler);
    server.start();
}