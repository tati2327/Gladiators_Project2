
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

template<typename T>
void Node<T>::setData(T _data){
    data = _data;
}

template<typename T>
void Node<T>::setNode(Node<T> _node){
    data = _node.data;
}
