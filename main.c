#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h> // for getnameinfo()

// Usual socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#include "response.h"
#include "request.h"

#define IP_ADDR "0.0.0.0"
#define PORT_ADDR 1234

#define SIZE 1024
#define BACKLOG 10  // Passed to listen()

#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

void report(struct sockaddr_in *serverAddress);

int main(void)
{
    char response[65536];
    char request[4096];

    // Socket setup: creates an endpoint for communication, returns a descriptor
    // -----------------------------------------------------------------------------------------------------------------
    int serverSocket = socket(
        AF_INET,      // Domain: specifies protocol family
        SOCK_STREAM,  // Type: specifies communication semantics
        0             // Protocol: 0 because there is a single protocol for the specified family
    );

    // Construct local address structure
    // -----------------------------------------------------------------------------------------------------------------
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(1235);
    serverAddress.sin_addr.s_addr = inet_addr(IP_ADDR); //htonl(INADDR_LOOPBACK);

    // Bind socket to local address
    // -----------------------------------------------------------------------------------------------------------------
    // bind() assigns the address specified by serverAddress to the socket
    // referred to by the file descriptor serverSocket.
    bind(
        serverSocket,                         // file descriptor referring to a socket
        (struct sockaddr *) &serverAddress,   // Address to be assigned to the socket
        sizeof(serverAddress)                 // Size (bytes) of the address structure
    );

    // Mark socket to listen for incoming connections
    // -----------------------------------------------------------------------------------------------------------------
    int listening = listen(serverSocket, BACKLOG);
    if (listening < 0) {
        printf("Error: The server is not listening.\n");
        return 1;
    }
    report(&serverAddress);     // Custom report function
    readImage("download.jpg",response);
    int clientSocket;
    ssize_t valread;

    // Wait for a connection, create a connected socket if a connection is pending
    // -----------------------------------------------------------------------------------------------------------------
    while(1) {
        clientSocket = accept(serverSocket, NULL, NULL);
        valread = read(clientSocket , request, 4096);
        getHead(request);
        //printf("%sRequest from blabla%s\n%s\n\n",COLOR_GREEN,COLOR_RESET,request);
        send(clientSocket, response, sizeof(response), 0);
        close(clientSocket);
    }
    return 0;
}

void report(struct sockaddr_in *serverAddress)
{
    char hostBuffer[INET6_ADDRSTRLEN];
    char serviceBuffer[NI_MAXSERV]; // defined in `<netdb.h>`
    socklen_t addr_len = sizeof(*serverAddress);
    int err = getnameinfo(
        (struct sockaddr *) serverAddress,
        addr_len,
        hostBuffer,
        sizeof(hostBuffer),
        serviceBuffer,
        sizeof(serviceBuffer),
        NI_NUMERICHOST
    );
    if (err != 0) {
        printf("It's not working!!\n");
    }
    printf("\n\n\tServer listening on http://%s:%s\n", hostBuffer, serviceBuffer);
}