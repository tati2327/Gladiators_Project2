#include <iostream>
#include "Army.h"
#include "List.h"


int main() {

    Army army(20);
    army.createArmy(army.armySize);

    //army.printArray(army.gladiators, 20);
    army.insertionSort(army.gladiators);
    cout<<"lista ordenada"<<endl;
    army.printArray(army.gladiators, 20);

    /*List<string> list;
    list.add("Hello");
    list.add("Another message");
    list.add("Third message!");
    list.show();
    cout<<"Despues de eliminarse el primer elemento..."<<endl;
    list.deleteNode("Hello");
    list.show();*/


    return 0;
}