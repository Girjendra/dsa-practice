#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* prev;
    node* next;

    // Consrtuctor
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Desrtuctor
    ~node(){
        cout<<"node delete for node data "<<this->data<<endl;
    }
};

// Printing Linked list
void printLL(node* head,node* tail){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"head :"<<head->data<<endl;
    cout<<"tail :"<<tail->data<<endl;
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

// Insertion at starting
void insertathead(node* &head,node* &tail,int elem){
    if(head == NULL){
        node* temp = new node(elem);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(elem);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insertion at ending
void insertattail(node* &head,node* &tail,int elem){
    if(tail == NULL){
        node* temp = new node(elem);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(elem);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insertion at position
void insertatmid(node* &tail,node* &head,int position,int elem){

    // Insertion at starting
    if(position == 0){
        insertathead(head,tail,elem);
        return ;
    }

    node* temp = head;
    int count = 1;

    while(count < position){
        temp = temp->next;
        count++;
    }

    // Insertion at ending
    if(temp->next == NULL){
        insertattail(head,tail,elem);
        return ;
    }

    node* midnode = new node(elem);

    midnode->next = temp->next;
    temp->next->prev = midnode;
    temp->next = midnode;
    midnode->prev = temp;
}

void deleteposition(node* &head,node* &tail,int position){
    // Deleting starting node
    if(position == 0){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
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
            previous->next = NULL;
            tail = previous;
            delete current;
            return ;
        }

        // Deleting any mid node
        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    
    insertathead(head,tail,12);
    insertathead(head,tail,15);

    insertattail(head,tail,34);
    insertattail(head,tail,56);
    
    insertatmid(tail,head,3,78);
    insertatmid(tail,head,1,88);
    insertatmid(tail,head,0,108);
    insertatmid(tail,head,7,68);
    cout<<"Length of Linked list is: "<<getlength(head)<<endl;
    printLL(head,tail);

    deleteposition(head,tail,0);
    printLL(head,tail);
    deleteposition(head,tail,4);
    printLL(head,tail);
    deleteposition(head,tail,5);
    printLL(head,tail);

    return 0;
}