/* ================================================= Related List functions template =================================================*/

template <typename T> void List<T>::push_front(T val) {
    node_s *n = new node_s;
    n->next = head->next;
    n->prev = head;
    head->next->prev = n;
    head->next = n;
    n->value = val;
    size++;
}

template <typename T> void List<T>::push_back(T val) {
    node_s *n = new node_s;
    n->next = head;
    head->prev->next = n;
    n->prev = head->prev;
    head->prev = n;
    n->value = val;
    size++;
}

template <typename T> T List<T>::pop_back() {
    if(!isEmpty()) {
    node_s *tmp = head->prev;
    tmp->prev->next = head;
    head->prev = tmp->prev;
    auto val = tmp->value;
    delete tmp;
    size--;
    return val;
    } else {
        throw std::underflow_error("Empty List!\n");
    } 
}

template <typename T> T List<T>::pop_front() {
    if(!isEmpty()) {
    node_s *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    auto val = tmp->value;
    delete tmp;
    size--;
    return val; 
    } else {
        throw std::underflow_error("Empty List!\n");
    }
}
