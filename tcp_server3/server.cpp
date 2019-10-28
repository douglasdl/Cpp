/*
 * Simple Echo Server
 * Compile: g++ -o server  server.cpp
 * Execute: ./server
 */

#include "server.hpp"

using namespace std;

int main() 
{
    int DOMAIN = AF_INET;   // IPv4 communication; PF = Protocol Family; AF = Address Family; PF_INET = AF_INET
    int TYPE = SOCK_STREAM; // SOCK_STREAM = TCP; SOCK_DGRAM = UDP
    int PROTOCOL = 0;       // Internet Protocol (IP)
    int sockfd;             // Socket File Descriptor           sock
    int clientSocket;       // Client Socket File Descriptor    new
    int PORT = 10000;       // Port Number
    sockaddr_in server;     // To bind
    sockaddr_in client;     // To accept
    int data_len;
    char data[MAX_DATA];
    unsigned int length; // Size of the structure (sockaddr_in)
    char message[] = "Teste Client-Servidor TCP/IP!\n";
    int sent;   // Number of sent bytes
    
    // Create a socket - A Connection Endpoint
    sockfd = socket(DOMAIN, TYPE, PROTOCOL); 
    if(sockfd == ERROR) {
        cerr << "Can't create a socket!\n";
        return -1;
    }

    // Bind - Attaching the socket to an IP and Port
    server.sin_family = DOMAIN;
    server.sin_port = htons(PORT);   // Host to Network Short conversion
    server.sin_addr.s_addr = INADDR_ANY; // All interfaces in the local machine (0.0.0.0)
    //inet_pton(DOMAIN, "172.16.50.114", &server.sin_addr);  //
    inet_pton(DOMAIN, "127.0.0.1", &server.sin_addr);
    bzero(&server.sin_zero, 8); // Set 8 bytes to 0

    length = sizeof(sockaddr_in);
    if(bind(sockfd, (sockaddr*)&server, length) == ERROR) {
        cerr << "Can't bind to IP/Port\n";
        return -2;
    }

    // Listen - Wait for a connection
    int backlog = MAX_CLIENTS; // Maximum length of the pending connections queue
    if(listen(sockfd, backlog) == ERROR ) {
        cerr << "Can't listen!\n";
        return -3;
    }

    // Accept - A new connection
    while(1) { // Better signal handling required
        clientSocket = accept(sockfd, (sockaddr*)&client, &length);
        if(clientSocket == ERROR) {
            cerr << "Problem with client connecting!\n";
            return -4;
        }
        printf("New client connected from port no %d and IP %s\n", ntohs(client.sin_port), inet_ntoa(client.sin_addr));
        data_len = 1;
        
        while(data_len) {
            data_len = recv(clientSocket, data, MAX_DATA, 0);
            if(data_len) {
                // Send the message
                send(clientSocket, data, data_len, 0);
                data[data_len] = '\0';
                printf("Sent message: %s\n", data);
            }
        }
        
        printf("Client disconnected\n");
        close(clientSocket);
    }
}