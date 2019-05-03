#ifndef JSON_H
#define JSON_H


#include <iostream>
#include "include/rapidjson/allocators.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "list.h"

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

#endif // JSON_H
