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

string JSON::serializePlay(int id, int age, int survivalProb, int expectedGen, int emotionalIntelligent,
                           int uperStrenght, int lowerStrenght, int resistance, int physicalCondition,
                           List<string> obstacles, List<string> route) {
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





