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

string JSON::serializeNewPlay() {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember("request",1, allocator);
    document.AddMember("message","nuevo juego", allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"*****************messageServer******************************************"<<endl;
    return strbuf.GetString();
}

string JSON::serializeNextIteration() {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember("request",2, allocator);
    document.AddMember("message","otra iteración..", allocator);

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

List<string> JSON::getObstacles() {
    List<string> obstacles;
    Value temp = document["obstacles"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        obstacles.add(temp[i].GetString());
    }
    return obstacles;
}

List<string> JSON::getRoute() {
    List<string> rute;
    Value temp = document["rute"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        rute.add(temp[i].GetString());
    }
    return rute;
}

int JSON::getId() {
    return document["id"].IsInt();
}

int JSON::getAge() {
    return document["age"].GetInt();
}

int JSON::getSurvivalProb() {
    return document["survivalProb"].GetInt();
}

int JSON::getExpectedGen() {
    return document["expectedGen"].GetInt();
}

int JSON::getEmocionalIntelligent() {
    return document["emocionalIntelligent"].GetInt();
}

int JSON::getUperStrenght() {
    return document["uperStrenght"].GetInt();
}

int JSON::getLowerStrenght() {
    return document["lowerStrenght"].GetInt();
}

int JSON::getResistance() {
    return document["resistance"].GetInt();
}

int JSON::getPhysicalCondition() {
    return document["physicalCondition"].GetInt();
}

int JSON::getTime() {
    return document["time"].GetInt();
}

int JSON::getIteration() {
    return document["iteration"].GetInt();
}







