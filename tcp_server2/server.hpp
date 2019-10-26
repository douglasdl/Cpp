#pragma once

#include <cstring>      // bzero(), strlen()
#include <iostream>     // cerr
#include <arpa/inet.h>  // inet_pton(), inet_ntoa()
#include <unistd.h>     // read(), close()
#include <sys/types.h>  // socket(), bind(), listen(), connect(), send(), recv()
#include <sys/socket.h> // socket(), bind(), listen(), connect(), send(), recv(), inet_ntoa()
#include <netinet/in.h> // inet_ntoa(), struct 
/*
struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;    // Port Number
    struct in_addr sin_addr;    // IP Address
    char sin_zero[8];
};

struct in_addr {
    unsigned long s_addr;   // 4 bytes long
};
*/