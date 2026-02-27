#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;

    // Consrtuctor
    node(int data){
        this->data = data;
        this->next = NULL;
    }

    // Desrtuctor
    ~node(){
        cout<<"node delete for node data "<<this->data<<endl;
    }
};

// Insertion after a reference element
void insertatelement(node* &tail,int refelem,int insertelem){
    // Assuming that refelem is present in the Linked list

    // Empty Linked list
    if(tail == NULL){
        node* newnode = new node(insertelem);
        tail = newnode;
        tail->next = tail;
        return ;
    }
    // Non empty Linked list
    else{
        node* current = tail;
        while(current->data != refelem){
            current = current->next;
        }

        node* newnode = new node(insertelem);
        newnode->next = current->next;
        current->next = newnode;
    }
}

// Deleting a given element
void deleteelement(node* &tail,int elem){

    // Empty list
    if(tail == NULL){
        cout<<"List is empty to delete anything"<<endl;
        return ;
    }

    
    node* previous = tail;
    node* current = tail->next;
    
    while(current->data != elem){
        previous = current;
        current = current->next;
        
        // If we've come full circle and didn't find the element
        if (current == tail->next) {
            cout << "Element not found" << endl;
            return;
        }
    }
    
    previous->next = current->next;

    // Only one node
    if (current == previous) {
        tail = NULL;
    }
    
    // If deleting the tail node
    if (current == tail) {
        tail = previous;
    }

    current->next = NULL;
    delete current;
}

// Printing Linked list
void printLL(node* tail){

    if (tail == NULL) {
        cout << "List is empty to print" << endl;
        return;
    }

    node* temp = tail;
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    }while (tail != temp);
    cout<<endl;
}

int main(){
    node* tail = NULL;
    insertatelement(tail,3,5);
    printLL(tail);
    insertatelement(tail,5,2);
    printLL(tail);
    insertatelement(tail,2,9);
    printLL(tail);
    insertatelement(tail,2,3);
    printLL(tail);
    
    deleteelement(tail,5);
    deleteelement(tail,2);
    deleteelement(tail,9);
    deleteelement(tail,3);
    deleteelement(tail,3);
    printLL(tail);
    return 0;
}