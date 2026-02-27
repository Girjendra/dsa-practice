
// O(m+n) O(max(m,n))
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
void printLL(node* head){
    node* temp = head;
    while (temp != NULL){
        cout<< temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

// Reverse the Linked list
node* reverseLinkedList(node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* previous = NULL;
    node* current = head;
    node* forward = head;
    while (current != NULL) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

// Create a new node and add it to new linked list
void addnode(node* &head, node* &current, int elem){
    node* newnode = new node(elem);
    
    if(head == NULL){
        head = newnode;
        current = newnode;
    }
    else{
        current->next = newnode;
        current = newnode;
    }
}

// Add two Linked lists
node* addtwonumbers(node* first,node* second){
    first = reverseLinkedList(first);
    second = reverseLinkedList(second);

    node* headofsum = NULL;
    node* current = NULL;
    int carry = 0;

    while(first != NULL || second != NULL || carry != 0){
        int n1 = 0;
        int n2 = 0;
        int sum = 0;

        if(first != NULL){
            n1 = first->data;
            first = first->next;
        }

        if(second != NULL){
            n2 = second->data;
            second = second->next;
        }

        sum = n1 + n2 + carry;
        
        addnode(headofsum, current, sum % 10);

        carry = sum / 10;
    }

    headofsum = reverseLinkedList(headofsum);

    // Remove leading Zeros
    while(headofsum->data == 0)
        headofsum = headofsum->next;

    return headofsum;
}

int main(){
    node* first = new node(1);
    first->next = new node(3);
    first->next->next = new node(3);

    node* second = new node(3);
    second->next = new node(2);
    second->next->next = new node(4);
    second->next->next->next = new node(6);

    cout<<"First number: ";
    printLL(first);

    cout<<"Second number: ";
    printLL(second);

    node* headofsum = addtwonumbers(first,second);

    cout<<"Sum of linked lists: ";
    printLL(headofsum);
    return 0;
}