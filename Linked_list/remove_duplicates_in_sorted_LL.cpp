#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Printing Linked list
void printLL(node* &head){
    node* temp = head;
    while (temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

void removeDuplicates(node *head){
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;


    while(head->next != NULL){
        if(head->data != head->next->data)
            head = head->next;
        else{
            node* next_next = head->next->next;
            head->next->next = NULL;
            delete(head->next);
            head->next = next_next;
        }
    }
}
int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(5); 
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(6);

    printLL(head);
    cout<<"Linked list ater removing duplicates:"<<endl;
    removeDuplicates(head);
    printLL(head);
    return 0;
}