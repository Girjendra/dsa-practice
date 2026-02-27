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

node* kReverse(node* head, int k) {
    if(head == NULL)
        return head;

    // Check if n is less k
    node* temp = head;
    int count1 = 0;
    while(temp != NULL){
        temp = temp->next;
        count1++;
    }

    if(count1<k)
        return head;

    //Step 1 - Reverse first k nodes
    node* previous = NULL;
    node* current = head;
    node* next = current->next;
    int count = 0;

    while(current != NULL && count<k){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        count++;
    }

    // Step 2 - leave on recursion
    if(next != NULL)
        head->next = kReverse(next,k);

    // Step 3 - return the head of reversed list
    return previous;
}

int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(3);
    head->next->next->next->next->next->next = new node(8);
    head->next->next->next->next->next->next->next = new node(4);

    int k = 4;
    cout<<"The value of K is: "<<k<<endl;;

    // Print original list
    cout << "Original list: ";
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list
    head = kReverse(head,k);

    // Print reversed list
    cout << "Reversed list: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}