#include <iostream>

using namespace std;

//singly linked list implementation
class Node {
    public:
        int data;
        Node *next;
};

    void push(Node **head, int data){

        Node *newNode = new Node();
        //assigning data to the new node
        newNode->data = data;
        //assigning head node to new node's next pointer
        newNode->next = (*head);
        //changing head node to new node; 
        (*head) = newNode;
    }

    void insertAfter(Node *prevNode, int data){
        //checking is previous node is null 
        if(prevNode == NULL)
        {
            cout << "The given previous node cannot be NULL";
            return;
        }
        
        Node *newNode = new Node();
        //assigning data to new node 
        newNode->data = data;
        //assigning next pointer of new node to previous node next pointer 
        newNode->next = prevNode->next;
    }

    void append(Node **head, int data){
        Node *newNode = new Node();
        Node *last = *head;
        newNode->data = data;
        newNode->next = NULL;

        //checking to see if head is the only node 
        if(*head == NULL){

            *head = newNode;
            return;
        }
        //while last isn't the last node, traverse through the linked list 
        while(last->next != NULL){
            last= last->next;
        }
        //point the last node to the new node 
        last->next = newNode;
        return;

    }
    void deleteFirst(Node **head) {

        if (*head != NULL){
            //assigning head node to a temp node 
            Node *temp = *head;
            //changing head pointer to next node 
            *head = (*head)->next;
            //deallocating memory from previous head node 
            free(temp);
        }
    }

    void deleteMiddle(Node **head, int data){
        Node *mid = *head;
        Node *prev = NULL;

        while(mid->data != data){
            prev = mid; 
            mid = mid->next;
        }

        prev->next = mid->next;
        free(mid);

    }
    void deleteLast(Node **head){
        //assigning address of node to end 
        Node *end = *head;
        //empty pointer of Node 
        Node *prevNode = NULL;

        while (end->next != NULL){
            //prevNode is getting assigned address of end node pointer
            prevNode = end;
            //end is getting assigned the next node  
            end = end->next;
        }

        prevNode->next = NULL;
        free(end);
    }



int main()
{
    Node *head = NULL;
    append(&head, 14);
    push(&head, 5);
    push(&head, 12);
    push(&head, 100);
    push(&head, 132);

    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    
    deleteFirst(&head);
    deleteMiddle(&head, 5);
    deleteLast(&head);

    temp = head;

    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    return 0;
}