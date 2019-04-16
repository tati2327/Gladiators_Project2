using namespace std;

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
    curr = nullptr;
}

template<typename T>
void List<T>::add(T data) {
    if(!first) {
        /*! Si la lista esta vacia */
        first = new Node<T>;
        first->data = data;
        first->next = nullptr;
        last = first;
    } else {
        /*! Si la lista NO esta vacia */
        if(last == first) {
            /*! Si la lista tiene solo UN elemento */
            last = new Node<T>;
            last->data = data;
            last->next = nullptr;
            first->next = last;
        } else {
            /*! Si la lista tiene mas de un elemento */
            Node<T>* newData = new Node<T>;
            newData->data = data;
            newData->next = nullptr;
            last->next = newData;
            last = newData;
        }
    }
}

template<typename T>
void List<T>::deleteNode(T data) {
    if (first != nullptr) {
        Node<T> *auxDelete;
        //Node<T> *prev = nullptr;
        auxDelete = first;

        while ((auxDelete != nullptr) && (auxDelete->data != data)) {
            curr = auxDelete;
            auxDelete = auxDelete->next;
        }

        //No se encontró el elemento
        if (auxDelete == nullptr) {
            cout << "El elemento no existe"<<endl;
        } else if (curr == nullptr) { //El elemento es el primero de la lista
            first = first->next;
            delete(auxDelete);
        } else { //El elemento está en el medio o al final
            curr->next = auxDelete->next;
            delete(auxDelete);
        }
    }
}

template<typename T>
T List<T>::getData(int index) {
    if(index == 0) {
        // Get the first element
        return this->first->data;
    } else {
        // Get the index'th element
        Node<T>* curr = this->first;
        for(int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
}

template<typename T>
void List<T>::show(){
    curr = first;
    while (curr!= nullptr){
        cout << curr->getValue()<<endl; /*! Se recorre la lista con Curr y Curr.next*/
        curr = curr->getNext(); /*! En cada punto imprime el char */
    }
}

template<typename T>
int List<T>::size(){
    curr = first;
    int count=0;

    while(curr != nullptr){     /*! La lista se recorre con .getNext() y se tiene un contador para que
                                 *  crezca segun se recorra la lista*/
        curr = curr->getNext();
        count=count+1;
    }

    cout<<"El tamaño de la lista es"<<count<<endl;
    return count;
}

template<typename T>
T List<T>::operator [](int index) {
    return getData(index);
}