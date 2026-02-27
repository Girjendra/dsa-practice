// O(n) O(1)
#include<bits/stdc++.h>
using namespace std;
class node {
    public:
        int data;
        node *next;
        node *random;

        node(int x) {
            data = x;
            next = NULL;
            random = NULL;
        }
};

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

node* findmid(node* head) {
    node* slow = head;
    node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left,node* right){
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL) {
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // Remaing left list
    while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
    }

    // Remaing right list
    while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
    }

    // Return answer
    ans  = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Base case
    if(head == NULL || head->next == NULL)
        return head;
    
    // Breaking the linked list in two halves
    node* mid = findmid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // Recuesive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Now merge both halves
    head = merge(left ,right);

    // Return answer
    return head;
}

int main() {
    // Creating original linked list: 1->2->3->4
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    node* head = new node(3);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(6); 
    head->next->next->next->next->next = new node(2);
    head->next->next->next->next->next->next = new node(4);

    // Print original and cloned list data and random data
    cout << "Original List:\n";
    printList(head);

    node* newhead = mergeSort(head);
    cout << "\nCloned List:\n";
    printList(newhead);

    return 0;
}