// // O(n) O(n)
// #include<bits/stdc++.h>
// using namespace std;
// class Node {
//     public:
//         int data;
//         Node *next;
//         Node *random;

//         Node(int x) {
//             data = x;
//             next = NULL;
//             random = NULL;
//         }
// };

// // To insert a new node at the tail of the linked list
// void insertattail(Node* &head, Node* &tail, int elem) {
//     // Create a new node with the given data
//     Node* newnode = new Node(elem);

//     // If the list is empty, set head and tail to the new node
//     if (head == NULL) {
//         head = newnode;
//         tail = newnode;
//         return;
//     } else {
//         // Otherwise, append the new node at the end and update tail
//         tail->next = newnode;
//         tail = newnode;
//         return;
//     }
// }

// Node* cloneLinkedList(Node *head) {
        
//     // Step 1:Creating a clone list
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;
        
//     Node* temp = head;
        
//     while(temp != NULL){
//         insertattail(cloneHead,cloneTail,temp->data);
//         temp = temp->next;
//     }
        
//     // Step 2:Creating a map
//     unordered_map<Node*,Node*> mapping;
        
//     Node* originalnode = head;
//     Node* clonenode = cloneHead;
//     while(originalnode != NULL){
//         mapping[originalnode] = clonenode;
//         originalnode = originalnode->next;
//         clonenode = clonenode->next;
//     }
        
//     originalnode = head;
//     clonenode = cloneHead;
//     while(clonenode != NULL){
//         clonenode->random = mapping[originalnode->random];
//         originalnode = originalnode->next;
//         clonenode = clonenode->next;
//     }
//     return cloneHead;
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << "Node data: " << temp->data;
//         if (temp->random)
//             cout << ", Random points to: " << temp->random->data << endl;
//         else
//             cout << ", Random points to: NULL" << endl;
//         temp = temp->next;
//     }
// }

// int main() {
//     // Creating original linked list: 1->2->3->4
//     Node* head = NULL;
//     Node* tail = NULL;
//     insertattail(head, tail, 1);
//     insertattail(head, tail, 2);
//     insertattail(head, tail, 3);
//     insertattail(head, tail, 4);

//     // Setting up random pointers
//     // 1's random -> 3, 2's random -> 1, 3's random -> 4, 4's random -> 2
//     head->random = head->next->next;         // 1->3
//     head->next->random = head;               // 2->1
//     head->next->next->random = head->next->next->next; // 3->4
//     head->next->next->next->random = head->next;       // 4->2

//     // Cloning the list
//     Node* clonedHead = cloneLinkedList(head);

//     // Print original and cloned list data and random data
//     cout << "Original List:\n";
//     printList(head);

//     cout << "\nCloned List:\n";
//     printList(clonedHead);

//     return 0;
// }




// // O(n*n) O(n)
// #include<bits/stdc++.h>
// using namespace std;
// class Node {
//     public:
//         int data;
//         Node *next;
//         Node *random;

//         Node(int x) {
//             data = x;
//             next = NULL;
//             random = NULL;
//         }
// };

// // To insert a new node at the tail of the linked list
// void insertattail(Node* &head, Node* &tail, int elem) {
//     // Create a new node with the given data
//     Node* newnode = new Node(elem);

//     // If the list is empty, set head and tail to the new node
//     if (head == NULL) {
//         head = newnode;
//         tail = newnode;
//     } else {
//         // Otherwise, append the new node at the end and update tail
//         tail->next = newnode;
//         tail = newnode;
//     }
//     return ;
// }

// Node* cloneLinkedList(Node *head) {
        
//     // Step 1:Creating a clone list
//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;
        
//     Node* temp = head;
        
//     while(temp != NULL){
//         insertattail(cloneHead,cloneTail,temp->data);
//         temp = temp->next;
//     }
        
//     // Step 2:Connecting the random pointers
//     Node* temphead1 = head;
//     Node* clonetemp1 = cloneHead;

//     while(temphead1 != NULL){

//         Node* temphead2 = head;
//         Node* clonetemp2 = cloneHead;

//         while(temphead2 != NULL && temphead1->random != temphead2){
//             temphead2 = temphead2->next;
//             clonetemp2 = clonetemp2->next;
//         }

//         if(temphead1->random == temphead2){
//             clonetemp1->random = clonetemp2;
//         }

//         if(temphead2 == NULL){
//             clonetemp1->random = NULL;
//         }

//         temphead1 = temphead1->next;
//         clonetemp1 = clonetemp1->next;
//     }
//     return cloneHead;
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << "Node data: " << temp->data;
//         if (temp->random)
//             cout << ", Random points to: " << temp->random->data << endl;
//         else
//             cout << ", Random points to: NULL" << endl;
//         temp = temp->next;
//     }
// }

// int main() {
//     // Creating original linked list: 1->2->3->4
//     Node* head = NULL;
//     Node* tail = NULL;
//     insertattail(head, tail, 1);
//     insertattail(head, tail, 2);
//     insertattail(head, tail, 3);
//     insertattail(head, tail, 4);

//     // Setting up random pointers
//     // 1's random -> 3, 2's random -> 1, 3's random -> 4, 4's random -> 2
//     head->random = head->next->next;         // 1->3
//     head->next->random = head;               // 2->1
//     head->next->next->random = head->next->next->next; // 3->4
//     head->next->next->next->random = head->next;       // 4->2

//     // Cloning the list
//     Node* clonedHead = cloneLinkedList(head);

//     // Print original and cloned list data and random data
//     cout << "Original List:\n";
//     printList(head);

//     cout << "\nCloned List:\n";
//     printList(clonedHead);

//     return 0;
// }






// O(n) O(1)
#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node *random;

        Node(int x) {
            data = x;
            next = NULL;
            random = NULL;
        }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node data: " << temp->data;
        if (temp->random)
            cout << ", Random points to: " << temp->random->data << endl;
        else
            cout << ", Random points to: NULL" << endl;
        temp = temp->next;
    }
}

// To insert a new node at the tail of the linked list
void insertattail(Node* &head, Node* &tail, int elem) {
    // Create a new node with the given data
    Node* newnode = new Node(elem);

    // If the list is empty, set head and tail to the new node
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        // Otherwise, append the new node at the end and update tail
        tail->next = newnode;
        tail = newnode;
    }
    return ;
}


Node* cloneLinkedList(Node *head) {
        
    // Step 1:Creating a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
        
    while(temp != NULL){
        insertattail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    
    // Step 2: Add clonenodes in between original list
    Node* head1 = head;
    Node* clone1 = cloneHead;
    while(head1 != NULL && clone1 != NULL){
        // For original list
        Node* next1 = head1->next;
        head1->next = clone1;
        head1 = next1;

        // for clone list
        Node* next2 = clone1->next;
        clone1->next = head1;
        clone1 = next2;
    }

    // Step 3: Copy random pointers
    head1 = head;
    while(head1 != NULL){
        if(head1->next != NULL){
            head1->next->random = head1->random ? head1->random->next : head1->random;
        }
        head1 = head1->next->next;
    }

    // Step 3: Revert the changes done in step 2
    head1 = head;
    clone1 = cloneHead;
    while(head1 != NULL && clone1 != NULL){
        head1->next = clone1->next;
        head1 = head1->next;

        if(head1 != NULL)
            clone1->next = head1->next;
        clone1 = clone1->next;
    }

    // Step 4: Return the answer
    return cloneHead;
}


int main() {
    // Creating original linked list: 1->2->3->4
    Node* head = NULL;
    Node* tail = NULL;
    insertattail(head, tail, 1);
    insertattail(head, tail, 2);
    insertattail(head, tail, 3);
    insertattail(head, tail, 4);

    // Setting up random pointers
    // 1's random -> 3, 2's random -> 1, 3's random -> 4, 4's random -> 2
    head->random = head->next->next;         // 1->3
    head->next->random = head;               // 2->1
    head->next->next->random = head->next->next->next; // 3->4
    head->next->next->next->random = head->next;       // 4->2

    // Cloning the list
    Node* clonedHead = cloneLinkedList(head);

    // Print original and cloned list data and random data
    cout << "Original List:\n";
    printList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}