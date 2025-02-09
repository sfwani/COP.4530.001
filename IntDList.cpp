#include "IntDList.hpp"

// Constructor: Initializes an empty list
IntDLList::IntDLList() {
    head = nullptr;
    tail = nullptr;
}

// Destructor: Frees memory of all nodes
IntDLList::~IntDLList() {
    while (head) {
        deleteFromHead();
    }
}

// Add a new node to the head
void IntDLList::addToHead(int value) {
    IntDLLNode* newNode = new IntDLLNode(value, nullptr, head);
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode; // If list was empty, tail is also new node
    }
    head = newNode;
}

// Add a new node to the tail
void IntDLList::addToTail(int value) {
    IntDLLNode* newNode = new IntDLLNode(value, tail, nullptr);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// Insert a node while maintaining sorted order
void IntDLList::insertInOrder(int value) {
    if (!head || value <= head->info) {
        addToHead(value);
        return;
    }
    if (value >= tail->info) {
        addToTail(value);
        return;
    }

    IntDLLNode* current = head;
    while (current->info < value) {
        current = current->next;
    }

    IntDLLNode* newNode = new IntDLLNode(value, current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;
}

// Delete the head node and return its value
int IntDLList::deleteFromHead() {
    if (!head) throw std::runtime_error("List is empty");

    int value = head->info;
    IntDLLNode* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    return value;
}

// Delete the tail node and return its value
int IntDLList::deleteFromTail() {
    if (!tail) throw std::runtime_error("List is empty");

    int value = tail->info;
    IntDLLNode* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    return value;
}

// Delete a specific node by value
void IntDLList::deleteNode(int value) {
    IntDLLNode* current = head;
    while (current && current->info != value) {
        current = current->next;
    }
    if (!current) return;

    if (current == head) {
        deleteFromHead();
    } else if (current == tail) {
        deleteFromTail();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Check if a value exists in the list
bool IntDLList::isInList(int value) const {
    IntDLLNode* current = head;
    while (current) {
        if (current->info == value) return true;
        current = current->next;
    }
    return false;
}

// Print all elements in the list
void IntDLList::printAll() const {
    IntDLLNode* current = head;
    while (current) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Convert list to a string
std::string IntDLList::addToString() const {
    std::ostringstream oss;
    IntDLLNode* current = head;
    while (current) {
        oss << current->info;
        current = current->next;
    }
    return oss.str();
}
