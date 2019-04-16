template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

template<typename T>
void List<T>::add(T data) {
    if(!first) {
        // The list is empty
        first = new Node<T>;
        first->data = data;
        first->next = nullptr;
        last = first;
    } else {
        // The list isn't empty
        if(last == first) {
            // The list has one element
            last = new Node<T>;
            last->data = data;
            last->next = nullptr;
            first->next = last;
        } else {
            // The list has more than one element
            Node<T>* insdata = new Node<T>;
            insdata->data = data;
            insdata->next = nullptr;
            last->next = insdata;
            last = insdata;
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
T List<T>::operator [](int index) {
    return getData(index);
}