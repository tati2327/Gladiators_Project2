#include "client.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#include "game.h"
extern Game *g;
Client::Client() {
    newGame = false;
    port = 54000;
    ipAddress = "192.168.100.9";
}

void Client::newClient() {
    /*! Creo el socket del cliente*/
    sockClient = socket(AF_INET, SOCK_STREAM, 0);
    if (sockClient == -1) {
        cout<<"Error al crear el socket del cliente"<<endl;
        return;
    }

    /*! Crear una estructura para el servidor con el que nos estamos conectando*/
    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(static_cast<uint16_t>(port));
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    /*! Conectar al servidor en el socket*/
    int connectRes = connect(sockClient, (sockaddr *) &hint, sizeof(hint));
    if (connectRes == -1) {
        cout<<"Error al intentar la conexión"<<endl;
        return;
    }
    /*! Iniciamos un intercambio de datos con el servidor*/
    this->manageServer();
}

void Client::manageServer() {
    char buf[4096];
    string messageReived;
    string messageToSend;
    while(true) {
        JSON myJsonToSend; /*!< Instancia del Json para mandar mensajes*/
        if(!newGame){
            newGame = true;
            messageToSend = myJsonToSend.serializeNewPlay();
        } else {
            messageToSend = myJsonToSend.serializeNextIteration();
        }

        /*! Enviar mensaje al servidor*/
        int sendRes = static_cast<int>(send(sockClient, messageToSend.c_str(), strlen(messageToSend.c_str()), 0));
        if (sendRes == -1){
            cout << "No se pudo mandar mensaje al servidor!!"<<endl;
            continue;
        }

        /*! Espera una respuesta...*/
        memset(buf, 0, 4096);
        int bytesReceived = static_cast<int>(recv(sockClient, buf, 4096, 0));
        if (bytesReceived == -1){
            cout <<"Hubo un error al obtener respuesta del servidor"<<endl;
            close(sockClient);
        }else{
            JSON myJson; /*!< Instancia del Json para mandar mensajes*/
            /*! Se lee la respuesta del servidor*/
            messageReived = string(buf, static_cast<unsigned long>(bytesReceived));
            cout<<"SERVER: "<<messageReived << endl;
            sleep(1);
            myJson.jsonToDocument(messageReived);
            g->ID->setPlainText(QString(myJson.getId()));
            g->age->setPlainText(QString(myJson.getAge()));
            g->resistance->setPlainText(QString(myJson.getResistance()));
            g->expected_gen->setPlainText(QString(myJson.getExpectedGen()));
            g->upper_stregth->setPlainText(QString(myJson.getUperStrenght()));
            g->lower_stregth->setPlainText(QString(myJson.getLowerStrenght()));
            g->physical_condition->setPlainText(QString(myJson.getPhysicalCondition()));
            g->emotional_intelligence->setPlainText(QString(myJson.getEmocionalIntelligent()));



            /*! Atraves de myJson.get...() se obtienen los datos del gladeador, los obstaculos y la ruta
             * Despues se usan esos datos para colocarlos enn a pantalla, darle la ruta al gladiador y si
             * el jugador atraviesa la zona de intimidación bien se acaba el juego sino de manda a pedir
             * otra iteración
             */

            //if(myGame.play == true){
            //  cout<<"Simulación terminada, el gladiador atravesó la zona de intimidacion
            //  close(sockClient)
            //}
        }
    }
}
