#ifndef LIST_TPP
#define LIST_TPP

/* ================================================= Related List functions template =================================================*/

template <typename T> List<T>::List() : size(0) {
    head = new node_s;
    head->next = head;
    head->prev = head;
    head->sentinel = true;
}

template <typename T> bool List<T>::isEmpty() const { return (size == 0); }

template <typename T> int List<T>::getSize() const { return size; }

template <typename T> void List<T>::printList() const {
    if(!head) return;
    node_s *c = head->next;
    while(c != head) {
        std::cout << "[" << c->value << "]-->";
        c = c->next;
    }
    std::cout << std::endl;
}

template <typename T> void List<T>::printMemoryDump() const {
    std::cout << "\n=============== Memory Dump ===============\n";

    node_s *c = head;
    do {
    std::cout << "\nNode @ " << static_cast<void*>(c);
    if(c == head) {std::cout << "   [SENTINEL]\n"; } else { std::cout << std::endl; }
    std::cout << "  prev: " << static_cast<void*>(c->prev) << ((c->prev == head) ? "   (head)" : "") << "\n";
    std::cout << "  next: " << static_cast<void*>(c->next) << ((c->next == head) ? "   (head)" : "") << "\n";
    if(c != head) { std::cout << "  value: " << c->value << "\n\n"; }
    

    c = c->next;
    }while(c != head);
    std::cout << "===========================================\n";
}

template <typename T> List<T>::~List() {
    node_s *c = head->next;
    while(c != head) {
        node_s *tmp = c;
        c = c->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

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

#endif // LIST_TPP
