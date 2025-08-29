#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string>
#include "util.h"
#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    errif(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0, "WSAStartup failed");

    // Create server socket
    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
    errif(sockfd == INVALID_SOCKET, "socket creation failed.");
    
    // Bind to port 8888
    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_family = AF_INET;
    errif(bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR, "socket bind failed.");
    errif(listen(sockfd, SOMAXCONN) == SOCKET_ERROR, "listen error.");
    std::cout << "Server listening on 127.0.0.1:8888..." << std::endl;
    
    // Accept client connection
    sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    SOCKET clientfd = accept(sockfd, (sockaddr*)&client_addr, &client_addr_len);
    errif(clientfd == INVALID_SOCKET, "client accept failed.");
    std::cout << "new client from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << std::endl;

    // Echo messages back to client
    char buffer[1024];
    while (true) {
        memset(&buffer, 0, sizeof(buffer));
        if (int read_bytes = recv(clientfd, buffer, sizeof(buffer), 0); read_bytes > 0) {
            std::cout << "received from client: " << buffer << std::endl;
            const char* send_back = "server received message from client.\n";
            send(clientfd, send_back, strlen(send_back) + 1, 0);
        } else if (read_bytes == 0) {
            errif(true, "client disconnected.");
        } else {
            errif(true, "recv failed.");
        }
    }

    // Cleanup
    closesocket(clientfd);
    closesocket(sockfd);
    WSACleanup();
    return 0;
}