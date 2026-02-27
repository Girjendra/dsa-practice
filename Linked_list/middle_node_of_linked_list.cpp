// /*
// Given a singly linked list of 'N' nodes. The objective is to determine
// the middle node of a singly linked list. However, if the list has an
// even number of nodes, we return the second middle node.
// */
// #include<iostream>
// using namespace std;
// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// // O(n)
// int getlen(Node* head){
//     int len = 0;
//     while(head != NULL){
//         head = head->next;
//         len++;
//     }
//     return len;
// }
// Node *findMiddle(Node *head) {
//     if(head == NULL || head->next == NULL)
//         return head;
    
//     int len = getlen(head);
//     int mid = len/2;

//     int count = 0;
//     Node* temp = head;
//     while(count<mid){
//         temp = temp->next;
//         count++;
//     }
//     return temp;
// }

// int main(){
//     // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
//     Node* head = new Node(1);
//     head->next = new Node(2);
//     head->next->next = new Node(3);
//     head->next->next->next = new Node(4);
//     head->next->next->next->next = new Node(5); 
//     head->next->next->next->next->next = new Node(6);
    
//     Node* middlenode = findMiddle(head);
//     cout<<middlenode->data<<endl;
//     return 0;
// }


#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// O(n)
// Node *findMiddle(Node *head) {
//     // 1 Node
//     if(head == NULL || head->next == NULL)
//         return head;
    
//     // 2 Node
//     if(head->next->next == NULL)
//         return head->next;

//     Node* fast = head->next;
//     Node* slow = head;
//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL)
//             fast = fast->next;
//         slow = slow->next;
//     }
//     return slow;
// }

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = new Node(6);
    
    Node* middlenode = findMiddle(head);
    cout<<middlenode->data<<endl;
    return 0;
}