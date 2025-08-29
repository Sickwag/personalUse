#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")
int main() {
    // 初始化Windows Socket
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }

    // create socket in server
    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == INVALID_SOCKET){
        printf("socket failed %d\n.", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // set server address
    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    // bind server to socket 
    if(bind(sockfd,(sockaddr*)&serv_addr,sizeof(serv_addr)) == SOCKET_ERROR){
        printf("bind failed: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // listen this port
    if(listen(sockfd,SOMAXCONN) == SOCKET_ERROR){
        printf("listen failed: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("Server listening on 127.0.0.1:8888...\n");

    // accept client connection
    sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    memset(&client_addr, 0, sizeof(client_addr));
    SOCKET client_sockfd = accept(sockfd, (sockaddr*)&client_addr, &client_addr_len);
    if(client_sockfd == INVALID_SOCKET){
        printf("socket failed: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }
    printf("new client connection!, socket: %lld, IP: %s, Port: %d\n", client_sockfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    closesocket(sockfd);
    closesocket(client_sockfd);
    WSACleanup();
    return 0;
};
