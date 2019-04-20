#include "Field.h"

Field::Field() {
    this->empty = true;
    g = 0;
    h = 0;
    f = 0;
    i = 0;
    j = 0;
}

/*! Funcion que sera necesaria para luego agregar obstaculos */
bool Field::addObstacle() {
    return false;
}

bool Field::isEmpty() {
    return empty;
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