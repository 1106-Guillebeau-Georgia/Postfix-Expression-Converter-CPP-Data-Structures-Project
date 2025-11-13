//Author :: Georgia Guillebeau
//Date: 06.12.2025
//Purpose: Linked implmentation of the stack data structure
#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template <class ItemType>
class LinkedStack: public StackInterface<ItemType>{
    //Private Attribute
    Node <ItemType>* top;

    public:
    //Default and Copy Constructors 
    LinkedStack();
    LinkedStack(const LinkedStack&);

    //Data Structure methods
    bool isEmpty() const override;
    bool push(const ItemType& newEntry) override;
    bool pop() override;
    ItemType peek() const override;

    ~LinkedStack(); //Not empty b/c of explicitly dynamically allocated nodes

};
#include "linkedStack.cpp"
#endif