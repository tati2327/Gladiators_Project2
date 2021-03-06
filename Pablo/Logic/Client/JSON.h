#ifndef SERVER_JSON_H
#define SERVER_JSON_H

#include <iostream>
#include <allocators.h>
#include <stringbuffer.h>
#include <document.h>
#include <writer.h>
#include "List.h"

using namespace rapidjson;
using namespace std;

class JSON {
    public:
        JSON();
        void jsonToDocument(string json);

        string serializeNewPlay();
        string serializeNextIteration();

        int getRequest();
        List<string> getObstacles();
        List<string> getRoute();
        int getId();
        int getAge();
        int getSurvivalProb();
        int getExpectedGen();
        int getEmocionalIntelligent();
        int getUperStrenght();
        int getLowerStrenght();
        int getResistance();
        int getPhysicalCondition();
};

#endif //SERVER_JSON_H
