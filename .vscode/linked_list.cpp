#include <iostream>

using namespace std;

//singly linked list implementation
template <class elemType>
struct Node {
    public:
        elemType data;
        Node *next;

        Node(){
            next = NULL;
        }

        Node(const elemType &data){
            this->data = data;
            this->next = NULL;
        }
};

template <class elemType>
class LinkedList{
public:
    LinkedList();
    int size() const;
    void print() const;
    void push(const elemType &data);
    void insertAfter(const elemType &data1, const elemType &data2);
    void append(const elemType &data);
    void pop();
    void removeAt(const elemType &data);
    void removeEnd();
    void clearOut();
    void print();
    LinkedList &operator=(const LinkedList <elemType>&);
    ~LinkedList();
private:
    //const int size;
    Node<elemType> *myListHead;
};

template<class elemType>
LinkedList<elemType>::LinkedList(){
    myListHead = NULL;
    //size = 0;
}

template<class elemType>
LinkedList<elemType>::~LinkedList(){
    clearOut();
}
template<class elemType>
LinkedList<elemType>& LinkedList<elemType>::operator=(const LinkedList<elemType> &newList){
    clearOut();
    Node<elemType> *copyList = newList->head;
    Node<elemType> *tmp = NULL; 

    while(copyList){
        Node<elemType> *newNode = new Node<elemType>(copyList->data);

        if(tmp == NULL){
            myListHead = tmp;
        } 
        else {
            tmp->next = newNode;
        }
        tmp = newNode;
        copyList = copyList->next;
    }
    return *this;
}
template<class elemType>
void LinkedList<elemType>::push(const elemType &data){
    Node<elemType> *newNode = new Node<elemType>(data);

    //assigning head node to new node's next pointer
    newNode->next = myListHead;
    //changing head node to new node; 
    myListHead = newNode;
}
template<class elemType>
void LinkedList<elemType>::insertAfter(const elemType &data1, const elemType &data2){
    Node<elemType> *newNode = new Node<elemType>(data1);

    if(myListHead == NULL){
        myListHead = newNode;
    }
    else {
        Node<elemType> *node = myListHead;

        while(node->data != data2 && node->next != NULL){
            node = node->next;
        }

        if(node->next == NULL){
            node->next = newNode;
        }
        else{
            newNode->next = node->next;
            node->next = newNode;
        }
    }
    //assigning next pointer of new node to previous node next pointer 
     
}

template<class elemType>
void LinkedList<elemType>::append(const elemType &data){
    Node<elemType> *node = myListHead;
    Node<elemType> *newNode = new Node<elemType>(data);

    //checking to see if head is the only node 
    if(myListHead == NULL){
        myListHead = newNode;
        return;
    }

    //while last isn't the last node, traverse through the linked list 
     while(node->next != NULL){
        node = node->next;
    }
    //point the last node to the new node 
    node->next = newNode;

}
template<class elemType>
void LinkedList<elemType>::pop() {
    if (myListHead != NULL){
    //assigning head node to a temp node 
    Node<elemType> *tmp = myListHead;
                
    //changing head pointer to next node 
    myListHead = myListHead->next;
    //deallocating memory from previous head node 
    delete tmp;
    }
}
template<class elemType>
void LinkedList<elemType>::removeAt(const elemType &data){
    Node<elemType> *mid = myListHead;
    Node<elemType> *prev = NULL;

    while(mid->data != data){
        prev = mid; 
        mid = mid->next;
    }

    prev->next = mid->next;
    delete mid; 
}

template<class elemType>
void LinkedList<elemType>::removeEnd(){
    //assigning address of node to end 
    Node<elemType> *end = myListHead;
    //empty pointer of Node 
    Node<elemType> *prevNode = NULL;

    while (end->next != NULL){
        //prevNode is getting assigned address of end node pointer
        prevNode = end;
        //end is getting assigned the next node  
        end = end->next;
    }

    prevNode->next = NULL;
    delete end;
}

template<class elemType>
void LinkedList<elemType>::clearOut(){
    Node<elemType> *tmp = NULL; 
    
    while(myListHead){
        tmp = myListHead; 
        myListHead = myListHead->next;
        delete tmp;
    }

}
template<class elemType>
void LinkedList<elemType>::print(){
    while(myListHead){
        cout << myListHead->data << endl;
        myListHead = myListHead->next;
    }
}


int main()
{
    LinkedList<int> a;

    a.append(5);
    a.append(6);
    a.append(7);
    a.append(10);
    a.insertAfter(2,7);
    a.insertAfter(12, 5);
    a.insertAfter(15, 10);
    a.push(1);
    //a.pop();
    //a.pop();
   // a.removeAt(2);
    //a.removeAt(6);
    //a.removeEnd();
    a.print();
    return 0;
}