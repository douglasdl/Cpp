// TCP Server
#include "server.hpp"

using namespace std;

int main() 
{
    int DOMAIN = AF_INET;   // IPv4 communication; PF = Protocol Family; AF = Address Family; PF_INET = AF_INET
    int TYPE = SOCK_STREAM; // SOCK_STREAM = TCP; SOCK_DGRAM = UDP
    int PROTOCOL = 0;       // Internet Protocol (IP)
    int sockfd;             // Socket File Descriptor
    int clientSocket;       // Client Socket File Descriptor
    int PORT = 10000;       // Port Number
    sockaddr_in server;     // To bind
    sockaddr_in client;     // To accept
    unsigned int length; // Size of the structure (sockaddr_in)
    char message[] = "Teste Client-Servidor TCP/IP!\n";
    int sent;   // Number of sent bytes
    
    // Create a socket - A Connection Endpoint
    sockfd = socket(DOMAIN, TYPE, PROTOCOL); 
    if(sockfd == -1) {
        cerr << "Can't create a socket!\n";
        return -1;
    }

    // Bind - Attaching the socket to an IP and Port
    server.sin_family = DOMAIN;
    server.sin_port = htons(PORT);   // Host to Network Short conversion
    server.sin_addr.s_addr = INADDR_ANY;
    //inet_pton(DOMAIN, "172.16.50.114", &server.sin_addr);  //
    inet_pton(DOMAIN, "127.0.0.1", &server.sin_addr);
    bzero(&server.sin_zero, 8); // Set 8 bytes to 0

    length = sizeof(sockaddr_in);
    if(bind(sockfd, (sockaddr*)&server, length) == -1) {
        cerr << "Can't bind to IP/Port\n";
        return -2;
    }

    // Listen - Wait for a connection
    int backlog = SOMAXCONN; // Maximum length of the pending connections queue
    if(listen(sockfd, backlog) == -1 ) {
        cerr << "Can't listen!\n";
        return -3;
    }

    // Accept - A new connection
    while(1) {
        clientSocket = accept(sockfd, (sockaddr*)&client, &length);
        if(clientSocket == -1) {
            cerr << "Problem with client connecting!\n";
            return -4;
        }

        // Send the message
        sent = send(clientSocket, message, strlen(message), 0);
        printf("Sent %d bytes to client: %s\n", sent, inet_ntoa(client.sin_addr));

        close(clientSocket);
    }
}
//int getnameinfo(const struct sockaddr *addr, socklen_t addrlen,
//                       char *host, socklen_t hostlen,
//                       char *serv, socklen_t servlen, int flags);
//void *memset(void *s, int c, size_t n);