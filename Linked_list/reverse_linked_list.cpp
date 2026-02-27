#include <bits/stdc++.h>
using namespace std;
class LinkedListNode {
public:
    int data;
    LinkedListNode* next;
    LinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Iteratively O(n) which is optimal
void reverseLinkedList(LinkedListNode* &head) {
    if (head == NULL || head->next == NULL)
        return ;

    LinkedListNode* previous = NULL;
    LinkedListNode* current = head;
    LinkedListNode* forward = head;
    while (current != NULL) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    head = previous;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);

    // Print original list
    cout << "Original list: ";
    LinkedListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list
    reverseLinkedList(head);

    // Print reversed list
    cout << "Reversed list: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    temp = head;
    while (temp != NULL) {
        LinkedListNode* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;
// class LinkedListNode {
// public:
//     int data;
//     LinkedListNode* next;
//     LinkedListNode(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };


// // Recursively01 O(n) which is optimal
// void reverseLL(LinkedListNode *&head,LinkedListNode* previous,LinkedListNode* current){
//     if(current == NULL){
//         head = previous;
//         return ;
//     }

//     LinkedListNode* forward = current->next;
//     reverseLL(head,current,forward);
//     current->next = previous;
// }
// void reverseLinkedList(LinkedListNode *&head) {
        
//     LinkedListNode* previous = NULL;
//     LinkedListNode* current = head;
//     LinkedListNode* forward = head;
//     reverseLL(head,previous,current);
// }

// int main() {
//     // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
//     LinkedListNode* head = new LinkedListNode(1);
//     head->next = new LinkedListNode(2);
//     head->next->next = new LinkedListNode(3);
//     head->next->next->next = new LinkedListNode(4);
//     head->next->next->next->next = new LinkedListNode(5);

//     // Print original list
//     cout << "Original list: ";
//     LinkedListNode* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Reverse the list
//     reverseLinkedList(head);

//     // Print reversed list
//     cout << "Reversed list: ";
//     temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Free memory
//     temp = head;
//     while (temp != NULL) {
//         LinkedListNode* next = temp->next;
//         delete temp;
//         temp = next;
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// class LinkedListNode {
// public:
//     int data;
//     LinkedListNode* next;
//     LinkedListNode(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };
// // Recursively02 O(n) which is optimal
// LinkedListNode* reverseLL(LinkedListNode* head){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }

//     LinkedListNode* chotahead = reverseLL(head->next);
//     head->next->next = head;
//     head->next = NULL;

//     return chotahead;
// }

// void reverseLinkedList(LinkedListNode *&head) {
        
//     LinkedListNode* previous = NULL;
//     LinkedListNode* current = head;
//     LinkedListNode* forward = head;
//     head = reverseLL(head);
// }

// int main() {
//     // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
//     LinkedListNode* head = new LinkedListNode(1);
//     head->next = new LinkedListNode(2);
//     head->next->next = new LinkedListNode(3);
//     head->next->next->next = new LinkedListNode(4);
//     head->next->next->next->next = new LinkedListNode(5);

//     // Print original list
//     cout << "Original list: ";
//     LinkedListNode* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Reverse the list
//     reverseLinkedList(head);

//     // Print reversed list
//     cout << "Reversed list: ";
//     temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Free memory
//     temp = head;
//     while (temp != NULL) {
//         LinkedListNode* next = temp->next;
//         delete temp;
//         temp = next;
//     }

//     return 0;
// }