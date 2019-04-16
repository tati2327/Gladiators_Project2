using namespace std;

template<typename T>
T Node<T>::getValue(){
    //cout<<"El valor del nodo es "<<data<<endl;
    return data;
}

template<typename T>
Node<T>* Node<T>::getNext(){
    return next;
}
