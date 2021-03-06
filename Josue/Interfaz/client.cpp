#include "client.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#include "json.h"
extern int id;
extern int resis;
extern int jage;
extern int jlower;
extern int jupper;
extern int jexpec;
extern float jsurv;
extern int jphys;
extern int jem;
extern string obs1;
extern List<char> *movs;
extern bool status;
extern bool poner;
extern string rute;
extern int jtime;
extern int jiteration;
extern bool finished;
extern List<int> gid;
extern List<int> gresistance;
extern List<int> physical;
extern List<float> survival;
extern List<int> expected;
extern List<int> aget;
extern List<int> uppers;
extern List<int> lowers;
extern List<int> emotional;
extern bool movet;
int count;
extern bool ya;
extern bool graph;
Client::Client() {
    newGame = false;
    port = 54000;
    ipAddress = "192.168.1.4";
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
            count=1;
        } else {
            if (status){
                messageToSend=myJsonToSend.serializeNextIteration();
                count=1;
              }
            if (finished){
                messageToSend = myJsonToSend.serializeGraphic();
                finished=false;
                status=true;
                count=2;
              }
            if (movet){
                messageToSend = myJsonToSend.serializereorder();
                movet=false;
                status=true;
                count=3;
              }

        }
        int sendRes=-1;
        /*! Enviar mensaje al servidor*/
        if (status){
            sendRes= static_cast<int>(send(sockClient, messageToSend.c_str(), strlen(messageToSend.c_str()), 0));
            cout<<sendRes<<endl;
            status=false;
          }
        if (sendRes == -1){
            //cout << "No se pudo mandar mensaje al servidor!!"<<endl;
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
            if (count==3){
                myJson.jsonToDocument(messageReived);
                ya=true;
              }
            if (count==2){
                myJson.jsonToDocument(messageReived);\
                gresistance = myJson.getGraphicResistance();
                gid= myJson.getGraphicId();
                physical = myJson.getGraphicPhysicalCond();
                survival = myJson.getGraphicSurvivalProb();
                expected = myJson.getGraphicExpectedGen();
                aget = myJson.getGraphicAge();
                uppers = myJson.getGraphicUperStrenght();
                lowers = myJson.getGraphicLowerStrenght();
                emotional = myJson.getGraphicEmotionalInt();
                 graph=true;
                 close(sockClient);

              }
            cout<<"SERVER: "<<messageReived << endl;
            sleep(1);
            if (count==1){
                myJson.jsonToDocument(messageReived);
                id = myJson.getId();
                resis= myJson.getResistance();
                jage = myJson.getAge();
                obs1= myJson.obs1();
                jem = myJson.getEmocionalIntelligent();
                jexpec = myJson.getExpectedGen();
                jsurv = myJson.getSurvivalProb();
                jupper = myJson.getUperStrenght();
                jlower = myJson.getLowerStrenght();
                jphys = myJson.getPhysicalCondition();

                rute = myJson.rute();
                jiteration = myJson.getIteration();
                jtime = myJson.getTime();
                poner=true;
              }



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
