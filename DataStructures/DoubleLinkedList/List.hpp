#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

/* ========================================================= List Object =========================================================*/
template <typename T> class List {
public:

    List();
    bool isEmpty() const;
    void push_front(T ele);
    void push_back(T ele);
    T pop_front();
    T pop_back();

    int getSize() const;

    void printList() const;
    void printMemoryDump() const;

    ~List();

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

#include "List.tpp"

#endif // LIST_HPP
