#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

/* ========================================================= List Object =========================================================*/
template <typename T> class List {
public:

    List() : size(0) {
        head = new node_s;
        head->next = head;
        head->prev = head;
        head->sentinel = true;
    }

    bool isEmpty() const { return (size == 0); }
    int getSize() const { return size; }

    void printList() const {
        if(!head) return;
        node_s *c = head->next;
        while(c != head) {
            std::cout << "[" << c->value << "]-->";
            c = c->next;
        }
        std::cout << std::endl;
    }

    void printMemoryDump() const {
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

    ~List() {
        node_s *c = head->next;
        while(c != head) {
            node_s *tmp = c;
            c = c->next;
            delete tmp;
        }
        delete head;
        head = nullptr;
    }

    void push_front(T ele);
    void push_back(T ele);
    T pop_front();
    T pop_back();

private:
    typedef struct node {
        struct node *next;
        struct node *prev;
        T value;
        bool sentinel = false;
    } node_s;
    node_s *head;
    int size;  
};

// Push and Pop related functions template 
#include "List.cpp"

#endif // LIST_HPP
