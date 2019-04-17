#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

class Client{
    public:
        Client();
        int newClient();
};

#endif // CLIENT_H
