/*
 * Simple Echo Client
 * Compile: g++ -o client  client.cpp
 * Execute: ./client
 */

#include "client.hpp"

using namespace std;

int main() 
{
    int DOMAIN = AF_INET;   // IPv4 communication; PF = Protocol Family; AF = Address Family; PF_INET = AF_INET
    int TYPE = SOCK_STREAM; // SOCK_STREAM = TCP; SOCK_DGRAM = UDP
    int PROTOCOL = 0;       // Internet Protocol (IP)
    int sockfd;             // Socket File Descriptor           sock
    int clientSocket;       // Client Socket File Descriptor    new
    int PORT = 10000;       // Port Number
    sockaddr_in remote_server;     // To bind
    sockaddr_in client;     // To accept (sockaddr_in)
//int data_len;
    char input[BUFFER];
    char output[BUFFER];
    unsigned int length; // Size of the structure (sockaddr_in)

    // Create a socket - A Connection Endpoint
    sockfd = socket(DOMAIN, TYPE, PROTOCOL); 
    if(sockfd == ERROR) {
        cerr << "Can't create a socket!\n";
        return -1;
    }

    // Bind - Attaching the socket to an IP and Port
    remote_server.sin_family = DOMAIN;
    remote_server.sin_port = htons(PORT);   // Host to Network Short conversion
    remote_server.sin_addr.s_addr = INADDR_ANY; // All interfaces in the local machine (0.0.0.0)
    //inet_pton(DOMAIN, "172.16.50.114", &server.sin_addr);  //
    inet_pton(DOMAIN, "192.168.116.129", &remote_server.sin_addr);
    //inet_pton(DOMAIN, "127.0.0.1", &server.sin_addr);
    bzero(&remote_server.sin_zero, 8); // Set 8 bytes to 0

    length = sizeof(sockaddr_in);
    if((connect(sockfd, (sockaddr*)&remote_server, length)) == ERROR) {
        cerr << "Can't connect to the remote server\n";
        return -2;
    }

    // Receive
    while(1) {
        fgets(input, BUFFER, stdin);
        send(sockfd, input, strlen(input), 0); // Send the message
        
        length = recv(sockfd, output, BUFFER, 0);
        output[length] = '\0';
        printf("%s\n", output);
    }
    close(sockfd);
}