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

// Insertion at starting
void insertathead(node* &head,int elem){
    node* newnode = new node(elem);
    newnode->next = head;
    head = newnode;
}

// Insertion at ending
void insertattail(node* &tail,int elem){
    node* newnode = new node(elem);
    tail->next = newnode;
    tail = newnode;
}

// Insertion at position
void insertatmid(node* &tail,node* &head,int position,int elem){

    // Insertion at starting
    if(position == 0){
        insertathead(head,elem);
        return ;
    }

    node* temp = head;
    int count = 1;

    while(count <position){
        temp = temp->next;
        count++;
    }

    // Insertion at ending
    if(temp->next == NULL){
        insertattail(tail,elem);
        return ;
    }

    node* midnode = new node(elem);
    midnode->next = temp->next;
    temp->next = midnode;
}

void deleteposition(node* &head,node* &tail,int position){
    // Deleting starting node
    if(position == 0){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        node* previous = NULL;
        node* current = head;
        
        int count = 0;
        while(count<position){
            previous = current;
            current = current->next;
            count++;
        }
  
        // Deleting ending node
        if(current->next == NULL){
            previous->next = current->next;
            tail = previous;
            delete current;
            return ;
        }

        // Deleting any mid node
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

// Printing Linked list
void printLL(node* &head){
    node* temp = head;
    while (temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

// Getting length of LL
int getlength(node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

int main(){
    node* node1 = new node(45);
    node* head = node1;
    node* tail = node1;

    insertathead(head,12);
    insertathead(head,15);

    insertattail(tail,34);
    insertattail(tail,56);

    insertatmid(tail,head,3,78);
    insertatmid(tail,head,1,88);
    insertatmid(tail,head,0,108);
    insertatmid(tail,head,8,68);
    printLL(head);
    

    deleteposition(head,tail,0);
    deleteposition(head,tail,4);
    deleteposition(head,tail,6);
    printLL(head);
    cout<<"Length of Linked list is: "<<getlength(head)<<endl;
    return 0;
}