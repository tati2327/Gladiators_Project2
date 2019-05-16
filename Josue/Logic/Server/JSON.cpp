#include "JSON.h"
#include <cstdio>
#include <cstring>

using namespace rapidjson;
using namespace std;

Document document(kObjectType);

JSON::JSON() = default;

void JSON::jsonToDocument(string json) {
    document.Parse(json.c_str());
    cout<<"De json a documento exitosamente!!"<<endl;
}

string JSON::serializePlay(int id, int age, float survivalProb, int expectedGen, int emotionalIntelligent,
                           int uperStrenght, int lowerStrenght, int resistance, int physicalCondition,
                           List<string> obstacles, List<string> route, int time, int iteration) {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember("request",3, allocator);
    document.AddMember("id", id, allocator);
    document.AddMember("age", age, allocator);
    document.AddMember("survivalProb", survivalProb, allocator);
    document.AddMember("expectedGen", expectedGen, allocator);
    document.AddMember("emotionalIntelligent", emotionalIntelligent, allocator);
    document.AddMember("uperStrenght", uperStrenght, allocator);
    document.AddMember("lowerStrenght", lowerStrenght, allocator);
    document.AddMember("resistance", resistance, allocator);
    document.AddMember("physicalCondition", physicalCondition, allocator);

    /*! Creo el array*/
    Value myObstacles(kArrayType);
    Value myRoute(kArrayType);

    Value temp;
    /*! Agrega los obstaculos al JSON*/
    for(int i = 0; i<obstacles.size(); i++){
        temp.SetString((obstacles.getData(i)).c_str(),2,allocator);
        myObstacles.PushBack(temp, allocator);
    }

    /*! Agrega la ruta al JSON*/
    for(int i = 0; i<route.size(); i++){
        temp.SetString((route.getData(i)).c_str(),2,allocator);
        myRoute.PushBack(temp, allocator);
    }

    document.AddMember("obstacles", myObstacles, allocator);
    document.AddMember("route", myRoute, allocator);
    document.AddMember("time", time, allocator);
    document.AddMember("iteration", iteration, allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"***********************************************************"<<endl;
    return strbuf.GetString();
}

string JSON::serializeGraphic(List<int> resistance, List<int> uperStrenght, List<int> lowerStrenght,
                              List<int> emotionalInt, List<int> physicalCond, List<int> age,
                              List<int> expectedGenerations, List<float> survivalProb, List<int> fitness, List<int> id) {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();

    /*! Creo el array*/
    Value myResistance(kArrayType);
    Value myId(kArrayType);
    Value myAge(kArrayType);
    Value myUperStrenght(kArrayType);
    Value myLowerStrenght(kArrayType);
    Value myExpectedGenerations(kArrayType);
    Value mySurvivalProb(kArrayType);
    Value myFitness(kArrayType);
    Value myEmotionalInt(kArrayType);
    Value myPhysicalCond(kArrayType);


    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<resistance.size(); i++){
        myResistance.PushBack(resistance.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<uperStrenght.size(); i++) {
        myUperStrenght.PushBack(uperStrenght.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<id.size(); i++){
        myId.PushBack(id.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<lowerStrenght.size(); i++){
        myLowerStrenght.PushBack(lowerStrenght.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<emotionalInt.size(); i++){
        myEmotionalInt.PushBack(emotionalInt.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<physicalCond.size(); i++){
        myPhysicalCond.PushBack(physicalCond.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<age.size(); i++){
        myAge.PushBack(age.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<survivalProb.size(); i++){
        mySurvivalProb.PushBack(survivalProb.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<expectedGenerations.size(); i++){
        myExpectedGenerations.PushBack(expectedGenerations.getData(i), allocator);
    }
    /*! Agrega las resistencias al JSON*/
    for(int i = 0; i<fitness.size(); i++){
        myFitness.PushBack(fitness.getData(i), allocator);
    }

    document.AddMember("request",5, allocator);
    document.AddMember("resistance", myResistance, allocator);
    document.AddMember("uperStrenght", myUperStrenght, allocator);
    document.AddMember("lowerStrenght", myLowerStrenght, allocator);
    document.AddMember("emotionalIntelligent", myEmotionalInt, allocator);
    document.AddMember("physicalCondition", myPhysicalCond, allocator);
    document.AddMember("age", myAge, allocator);
    document.AddMember("survivalProb", mySurvivalProb, allocator);
    document.AddMember("expectedGen", myExpectedGenerations, allocator);
    document.AddMember("fitness", myFitness, allocator);
    document.AddMember("id", myId, allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"***********************************************************"<<endl;
    return strbuf.GetString();

}

int JSON::getRequest() {
    return document["request"].GetInt();
}





