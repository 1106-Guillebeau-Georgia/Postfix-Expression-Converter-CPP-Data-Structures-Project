//*If the comments begin to not make sense, the sleep got the best of me :/
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    top = nullptr;
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack& aStack){
    if(aStack.top == nullptr){
        top = nullptr;
    }
    else{
        top = new Node<ItemType>(); //Creates a new node for the top of the stack
        top->setItem(aStack.top->getItem());
        Node<ItemType>* temp = aStack.top->getNext(); //Traverse pointer
        Node<ItemType>* current = top; //Current node of the new copy of the stack, starts at the top of the stack
        while(temp != nullptr){
            Node<ItemType>* nextNode = new Node<ItemType>(); //New node for each item copied
            nextNode->setItem(temp->getItem()); //Gets the current item of the old stack and copies to next node of the new
            current->setNext(nextNode); //Set new current (new) stacks next node to the nextNode variable
            current = nextNode; //Moves new stack by 1
            temp = temp->getNext(); //Moves old stack by 1
        }
        current->setNext(nullptr); //Sets the lastNode to nullptr after entire stack was copied
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    if(top == nullptr){
        return true;
    }
    return false;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    //Dont check for emptiness b/c the stack is always able to be added to, we always add to the top
    Node<ItemType>* newNode = new Node<ItemType>(); //Create a new node so we can insert at the top
    newNode->setItem(newEntry); //Assign it the newEntry as its item
    newNode->setNext(top); //Have it point to the top of the stack
    top = newNode; //The top of the stack is now the newEntry
    return true; //Since the item was added
}   


template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    if(isEmpty() == true){
        return false; //Since it is empty there is no item that was removed
    }
    Node<ItemType>* deleteNode = top; //The node that is going to be deleted is the current top node
    top = top->getNext(); //Set the top to be the item under the current top
    delete deleteNode; //Actually delete the node
    return true; //Since the item has been popped off the top
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    if(isEmpty() == true){
        throw "Stack is empty";
    }
    return top->getItem();
}

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    while(isEmpty() == false){
        pop(); //Keep popping items off the top until the stack is empty
    }
}