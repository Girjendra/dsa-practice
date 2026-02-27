#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node* child;

        Node(int val) {
            data = val;
            next = NULL;
            child = NULL;
        }
};

// Insert at tail
void insertattail(Node* &head,Node* &tail,int elem){
    Node* newnode = new Node(elem);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else {
        tail->child = newnode;
        tail = newnode;
    }
}

Node* findmid(Node* head) {
    Node* slow = head;
    Node* fast = head->child;
    
    while(fast != NULL && fast->child != NULL){
        slow = slow->child;
        fast = fast->child->child;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL) {
        if(left->data < right->data){
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    // Remaing left list
    while(left != NULL){
            temp->child = left;
            temp = left;
            left = left->child;
    }

    // Remaing right list
    while(right != NULL){
            temp->child = right;
            temp = right;
            right = right->child;
    }

    // Return answer
    ans  = ans->child;
    return ans;
}

Node* mergeSort(Node *head) {
    // Base case
    if(head == NULL || head->child == NULL)
        return head;
    
    // Breaking the linked list in two halves
    Node* mid = findmid(head);

    Node* left = head;
    Node* right = mid->child;
    mid->child = NULL;

    // Recuesive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Now merge both halves
    head = merge(left ,right);

    // Return answer
    return head;
}

// To flat the linked list
Node* flattenLinkedList(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    Node* down = head;
    Node* newhead = NULL;
    Node* newtail = NULL;

    while(temp != NULL){

        while(down != NULL){
            insertattail(newhead,newtail,down->data);
            down = down->child;
        }
        temp = temp->next;
        down = temp;
    }
    newhead = mergeSort(newhead);
    return newhead;
}

int main() {
    Node* head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next = new Node(2);
    head->next->child = new Node(3);
    head->next->child->child = new Node(6);

    head->next->next = new Node(6);
    head->next->next->child = new Node(7);

    head->next->next->next = new Node(4);
    head->next->next->next->child = new Node(12);

    head->next->next->next->next = new Node(20);

    Node* flatHead = flattenLinkedList(head);

    // Print the flattened sorted list
    while (flatHead != NULL) {
        cout << flatHead->data << " -> ";
        flatHead = flatHead->child;
    }
    cout << "NULL" << endl;

    return 0;
}