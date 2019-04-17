#include "client.h"

using namespace std;

Client::Client(){

}

int Client::newClient(){
    /*! Crear un nuevo socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    /*! Crear una estructura de pistas para el servidor con el que nos estamos conectando. */
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(static_cast<uint16_t>(port));
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    /*! Conectar al servidor en el socket */
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }

    /*! while bucle: */
    char buf[4096];
    string userInput;


    do {
        /*! Enviar al servidor */
        int sendRes = static_cast<int>(send(sock, "Hola", userInput.size() + 1, 0));
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = static_cast<int>(recv(sock, buf, 4096, 0));
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            //		Display response
            cout << "SERVER> " << string(buf, static_cast<unsigned long>(bytesReceived)) << "\r\n";
        }
    } while(true);

    //	Close the socket
    close(sock);
    return 0;
}
