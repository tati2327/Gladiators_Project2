#ifndef SERVER_JSON_H
#define SERVER_JSON_H

#include <iostream>
#include <allocators.h>
#include <stringbuffer.h>
#include <document.h>
#include <writer.h>
#include "List.h"
#include "Field.h"

using namespace rapidjson;
using namespace std;

class JSON {
    public:
        JSON();
        void jsonToDocument(string json);
        string serializePlay(int id, int age, int survivalProb, int expectedGen, int emotionalIntelligent,
                             int uperStrenght, int lowerStrenght, int resistance, int physicalCondition,
                             List<string> obstacles, List<string> route, int time, int iteration);
        string serializeGraphic(List<int> resistance, List<int> uperStrenght, List<int> lowerStrenght,
                                List<int> emotionalInt, List<int> physicalCond, List<int> age, List<int> expectedGenerations,
                                List<int> survivalProb, List<int> fitness, List<int> id);

        int getRequest();
};

#endif //SERVER_JSON_H
