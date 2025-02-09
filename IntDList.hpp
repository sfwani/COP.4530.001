#ifndef INTDLIST_HPP
#define INTDLIST_HPP

#include "IntDList_node.hpp"
#include <iostream>
#include <string>
#include <sstream>

class IntDLList {
private:
    IntDLLNode* head;
    IntDLLNode* tail;

public:
    IntDLList();  // Constructor
    ~IntDLList(); // Destructor

    void addToHead(int value);
    void insertInOrder(int value);
    void addToTail(int value);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int value);
    bool isInList(int value) const;
    void printAll() const;
    std::string addToString() const;
};

#endif
