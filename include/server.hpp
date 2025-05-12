#ifndef SERVER_HPP
#define SERVER_HPP

class Server {
    public:
        Server(int port);
        void start();

    private:
        void setUpSocket();
        void handleClient(int clientSocket);

    private:
        int m_port;
        int m_socketDescr; 
};

#endif