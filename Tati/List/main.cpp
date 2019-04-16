#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List<string> list;
    list.add("Hello");
    list.add("Another message");
    list.add("Third message!");
    list.show();
    cout<<"Despues de eliminarse el primer elemento..."<<endl;
    list.deleteNode("Hello");
    list.show();
    return 0;
}