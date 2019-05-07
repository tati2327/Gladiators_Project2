
#include "Server.h"
#include "Server.h"
#include "Game.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <thread>

using namespace std;

void Server::initServer(){
    if(!newServer()) {
        cerr << "Error al crear el socket" << endl;
        return;
    }
    if(!flirtSO()) {
        cerr << "Error al conectar con el S.O." << endl;
        return;
    }

    this->addClient();
    this->manageClient(client.clientSocket);
}

bool Server::newServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        cerr << "Error al crear el socket" << endl;
        return false;
    }

    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "192.168.43.209 ", &hint.sin_addr);
    return true;
}

bool Server::flirtSO() {
    if (bind(serverSocket, (sockaddr *) &hint, sizeof(hint)) < 0){
        cerr << "Error al conectar con el S.O." << endl;
        return false;
    }

    listen(serverSocket, SOMAXCONN);
    return true;
}

void Server::addClient() {
    socklen_t clientSize = sizeof(client);

    cout << "Esperando cliente" << endl;
    client.clientSocket = accept(serverSocket, (sockaddr *) &client.info, &clientSize); /*!< Funcion bloqueante */

    char host[NI_MAXHOST]; /*!< Nombre remoto del cliente*/
    char service[NI_MAXSERV]; /*!< Servicio (puerto) en el que el cliente está conectado*/

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr *) &client.clientSocket, sizeof(client.clientSocket), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " conectado en el puerto " << service << endl;
    } else {
        inet_ntop(AF_INET, &client.info.sin_addr, host, NI_MAXHOST);
        cout << host << " conectado en el puerto " << ntohs(client.info.sin_port) << endl;
    }

    /*! Cerramos el socket del servidor para evitar errores*/
    close(serverSocket);
}

void Server::manageClient(int _client){
    char buf[4096];
    string message;

    while (true){
        memset(buf, 0, 4096);

        /*! Espera a que el cliente mande un mensaje*/
        int bytesReceived = recv(_client, buf, 4096, 0); /*!< Funcion bloqueante */
        if (bytesReceived == -1){
            cerr << "Error en los datos recibidos. Saliendo..." << endl;
            break;
        }

        if (bytesReceived == 0){
            cout << "Cliente desconectado" << endl;
            break;
        }

        message = string(buf, 0, bytesReceived);

        /*! Se imprime el mensaje del cliente*/
        cout<<"CLIENTE: "<<message << endl;
        sleep(1);
        /*! Aqui se abre un hilo para que el servidor brinde una respuesta */
        this->sendMessage(_client,message);
        //thread t_send(&Server::sendMessage, this, _client, message);
        //t_send.join();
    }
    close(client.clientSocket);
}

void Server::sendMessage(int _clientServer, string messageReceived){
    /*! Se pasa de JSON a un documento */
    JSON myJson; /*!< Instancia para enviar mensajes en formato json */
    myJson.jsonToDocument(messageReceived);
    srand(time(NULL));

    string messageToSend;
    if(myJson.getRequest() == 1){
        messageToSend = myGame.newGame();
    }if(myJson.getRequest() == 2){
        messageToSend = myGame.play();
    }

    /*!Se envia el mensaje*/
    send(_clientServer, messageToSend.c_str(), strlen(messageToSend.c_str()), 0);
}