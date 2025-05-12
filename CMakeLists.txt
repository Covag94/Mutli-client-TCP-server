cmake_minimum_required(VERSION 3.10)
project(TcpEchoServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# server executable
add_executable(tcp_echo_server
    src/server_main.cpp
    src/server.cpp)

# client executable
add_executable(tcp_echo_client
    src/client_main.cpp)