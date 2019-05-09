#include "json.h"
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

   // cout<<"***********************************************************"<<endl;
    //std::cout <<strbuf.GetString()<< std::endl;
   // cout<<"***********************************************************"<<endl;
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
        cout<<temp[i].GetString();
    }
    return obstacles;
}

List<string> JSON::getRoute() {
    List<string> rute;
    Value temp = document["route"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        rute.add(temp[i].GetString());
    }
    return rute;
}

string JSON::obs1()
{
  Value temp = document["obstacles"].GetArray();
  if (temp.Size()==3){
      string a=temp[0].GetString();
      string b=temp[1].GetString();
      string c=temp[2].GetString();
      string d=a+b+c;
      return d;
    }
  else {
      return "a";
    }


}

string JSON::rute()
{
    Value temp = document["route"].GetArray();
    string a = "";
    for(int i = 0; i < temp.Size(); i++){
        a=a+temp[i].GetString();
    }
    return a;
}



int JSON::getId() {
    return document["id"].GetInt();
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

List<int> JSON::getGraphicResistance() {
    List<int > resistance;
    Value temp = document["resistance"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        resistance.add(temp[i].GetInt());
    }
    return resistance;
}

List<int> JSON::getGraphicUperStrenght() {
    List<int > uperStrenght;
    Value temp = document["uperStrenght"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        uperStrenght.add(temp[i].GetInt());
    }
    return uperStrenght;
}

List<int> JSON::getGraphicLowerStrenght() {
    List<int > lowerStrenght;
    Value temp = document["lowerStrenght"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        lowerStrenght.add(temp[i].GetInt());
    }
    return lowerStrenght;
}

List<int> JSON::getGraphicEmotionalInt() {
    List<int > emotionalInt;
    Value temp = document["emotionalIntelligent"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        emotionalInt.add(temp[i].GetInt());
    }
    return emotionalInt;
}

List<int> JSON::getGraphicPhysicalCond() {
    List<int > physicalCondition;
    Value temp = document["physicalCondition"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        physicalCondition.add(temp[i].GetInt());
    }
    return physicalCondition;
}

List<int> JSON::getGraphicAge() {
    List<int > age;
    Value temp = document["age"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        age.add(temp[i].GetInt());
    }
    return age;
}

List<int> JSON::getGraphicSurvivalProb() {
    List<int > survivalProb;
    Value temp = document["survivalProb"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        survivalProb.add(temp[i].GetInt());
    }
    return survivalProb;
}

List<int> JSON::getGraphicExpectedGen() {
    List<int > expectedGen;
    Value temp = document["expectedGen"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        expectedGen.add(temp[i].GetInt());
    }
    return expectedGen;
}

List<int> JSON::getGraphicFitness() {
    List<int > fitness;
    Value temp = document["fitness"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        fitness.add(temp[i].GetInt());
    }
    return fitness;
}

List<int> JSON::getGraphicId() {
    List<int > id;
    Value temp = document["id"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        id.add(temp[i].GetInt());
    }
    return id;
}





