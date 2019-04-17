#include <iostream>
#include "Army.h"
#include "List.h"


int main() {

    /*Army army;
    army.createArmy(army.armySize);

    //army.printArray(army.gladiators, 20);
    army.insertionSort(army.gladiators);
    cout<<"lista ordenada"<<endl;
    army.printArray(army.gladiators, 20);*/

    /*List<string> list;
    list.add("Hello");
    list.add("Another message");
    list.add("Third message!");
    list.show();
    cout<<"Despues de eliminarse el primer elemento..."<<endl;
    list.deleteNode("Hello");
    list.show();*/



    srand(time(NULL));
    int random= (rand() % 7) + 0;

    for(int i=0; i<=random; i++){
        switch (i=0){
            case 0:
                cout<<"0"<<endl;

            case 1:
                cout<<"1"<<endl;

            case 2:
                cout<<"2"<<endl;

            case 3:
                cout<<"3"<<endl;

            case 4:
                cout<<"4"<<endl;

            case 5:
                cout<<"5"<<endl;

            case 6:
                cout<<"6"<<endl;
            case 7:
                cout<<"7"<<endl;
        }
    }


    return 0;
}