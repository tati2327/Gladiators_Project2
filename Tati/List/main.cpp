#include <iostream>
#include "List.h"
#include "Matrix.h"
#include "Field.h"
#include "Pathfinding.h"

using namespace std;

int main() {

    /*List<Field> *l1 = new List<Field>();
    Field m;
    Field n;
    Field k;

    l1->add(m);
    l1->add(n);
    l1->add(k);*/

    //cout<<"El nodo a eliminar es"<<l1.getNode(0)<<endl;
    //cout<<"De dato igual a "<<l1.getData(0)<<endl;

    //cout<<"Lista antes de eliminar...."<<endl;
    //l1.show();
    //l1.getNode(0)->next = l1.getNode(2)->next;
    Matrix<Field> m = Matrix<Field >(3,3);
    //cout<<&l1->getNode(0)->data<<endl;
    //cout<<&l1->getNode(1)->data<<endl;

    //l1->deleteNode(l1->getNode(0)->data);

    //cout<<&l1->getNode(0)->data<<endl;
    //cout<<"Lista despues de eliminar...."<<endl;

    Pathfinding p = Pathfinding(m);

    return 0;
}