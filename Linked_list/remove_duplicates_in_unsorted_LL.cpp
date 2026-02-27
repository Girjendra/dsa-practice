#include<bits/stdc++.h>
using namespace std;
#include<iostream>
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
// in O(1) O(n)
void removeDuplicates(node *head){
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;

    unordered_set<int> s;
    node* current = head;
    node* previous = NULL;

    while(current != NULL){
        if(s.find(current->data) == s.end()){
            s.insert(current->data);
            previous = current;
            current = current->next;
        }
        else{
            previous->next = current->next;
            node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

//    We can solve this problem in below ways also
// 1. using two for loops ===> O(n*n) O(1)
// 2. using map ===> O(n) ans O(n)
// 3. first sort the LL then remove duplicates ===> O(n*log(n)) O(1)

int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    node* head = new node(3);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(2); 
    head->next->next->next->next->next = new node(3);
    head->next->next->next->next->next->next = new node(-1);

    printLL(head);
    cout<<"Linked list ater removing duplicates:"<<endl;
    removeDuplicates(head);
    printLL(head);
    return 0;
}