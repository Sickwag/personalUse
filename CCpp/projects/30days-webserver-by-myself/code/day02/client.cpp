#include <windows.h>
#include <winsock2.h>
#include <iostream>
#include <string>
#include "util.h"
#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    errif(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0, "WSAStartup failed");

    // Create client socket
    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
    errif(sockfd == INVALID_SOCKET, "socket creation failed.");

    // Connect to server
    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    errif(connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR, "connect failed.");
    std::cout << "connected to server, type message to send(type \"exit\" to quit.)" << std::endl;

    // Send and receive messages
    char message[1024];
    while (true) {
        memset(&message, 0, sizeof(message));
        std::cin.getline(message, sizeof(message));

        if (strcmp(message, "exit") == 0)
            break;
        int send_bytes = send(sockfd, message, strlen(message) + 1, 0);
        errif(send_bytes == SOCKET_ERROR, "send bytes failed.");
        memset(&message, 0, sizeof(message));

        // receive echo message from server, remove those code if it isn't necessary
        int read_bytes = recv(sockfd, message, sizeof(message), 0);
        if (read_bytes > 0) {
            std::cout << "server replied: " << message << std::endl;
        } else if (read_bytes == 0) {
            std::cout << "Server disconnected." << std::endl;
            break;
        } else {
            errif(true, "Recv failed");
        }
    }

    // Cleanup
    closesocket(sockfd);
    WSACleanup();
    return 0;
}