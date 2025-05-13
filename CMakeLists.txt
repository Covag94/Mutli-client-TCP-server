cmake_minimum_required(VERSION 3.10)
project(TcpEchoServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# server executable
add_executable(server
    src/server_main.cpp
    src/server.cpp
    src/socket.cpp
    src/echo_handler.cpp)

# client executable
add_executable(client
    src/client_main.cpp)