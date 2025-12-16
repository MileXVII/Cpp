#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
public:
    List();
    ~List();
    
    bool isEmpty() const { return (size == 0); }
    int getSize() const { return size; }
    
    void printList() const;
    void printMemoryDump() const;
    
    void push_front(T ele);
    void push_back(T ele);
    T pop_front();
    T pop_back();

private:
    struct node {
        node *next;
        node *prev;
        T value;
        bool sentinel = false;
    };
    
    node *head; // sentinel
    int size;  
};

// including related functions template
#include "List.tpp"

#endif // LIST_HPP
