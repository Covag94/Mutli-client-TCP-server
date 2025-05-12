# TCP Multi-Client Echo Server

A basic TCP server in C++ that handles multiple clients concurrently using threads. Clients can connect, send messages, and receive their own messages echoed back from the server.

## Features

- Handles multiple clients simultaneously
- Uses `std::thread` to manage client sessions
- Implements a simple `EchoHandler` using a `ClientHandler` interface
- Modular and extensible architecture

## Build Instructions

### Prerequisites

- A C++17-compatible compiler (e.g., `g++`, `clang++`)
- [CMake](https://cmake.org/) version 3.10 or newer

### Build

```bash
mkdir build
cd build
cmake ..
make

### Run

In separate terminal windows or tabs, run the following:

1. **Start the server**  
   ```bash
   ./server

2. **Start client**
    ```bash
   ./client

