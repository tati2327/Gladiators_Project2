#include "Field.h"

Field::Field() {
    obstacle = false;
    inDiagonal = false;
    inLine = false;
    l = false;
    d = false;
    g = 0;
    h = 0;
    f = 0;
    i = 0;
    j = 0;
}

/*! Funcion que sera necesaria para luego agregar obstaculos */
bool Field::addObstacle() {
    obstacle = true;
    cout<<"Se agregó un obstaculo en "<<i<<j<<endl;
    return true;
}

bool Field::isObstacle() {
    if(obstacle){
        cout<<"Hay un obstaculo"<<endl;
    }else{
        cout<<"NO hay un obstaculo"<<endl;
    }
    return obstacle;
}

bool Field::equal(Field object) {
    return object.i == this->i && object.j == this->j;
}

/*! Misma función delete adaptada para borrar objetos de tipo campo*/
void Field::deleteField(Field _node, List<Field>& _list) {
    if (_list.first != nullptr) {
        Node<Field> *auxDelete;
        Node<Field> *curr = nullptr;
        auxDelete = _list.first;

        while ((auxDelete != nullptr) && !(auxDelete->data.equal(_node) )) {
            curr = auxDelete;
            auxDelete = auxDelete->next;
        }

        if (auxDelete == nullptr) {
            cout << "El elemento no existe"<<endl;
        } else if (curr == nullptr) {
            _list.first = _list.first->next;
            delete(auxDelete);
        } else if(auxDelete == _list.last) {
            _list.last = curr;
            curr->next = auxDelete->next;
            delete(auxDelete);
        } else{
            curr->next = auxDelete->next;
            delete(auxDelete);
        }
    }
}

void Field::setInLine(bool inLine) {
    if(l || inDiagonal)
        return;
    else
        Field::inLine = inLine;

}

void Field::setInDiagonal(bool inDiagonal) {
    if(d || inLine)
        return;
    else
        Field::inDiagonal = inDiagonal;
}
