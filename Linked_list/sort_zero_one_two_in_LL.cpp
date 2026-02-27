// O(n) O(1)
// #include<bits/stdc++.h>
// using namespace std;
// class node {
// public:
//     int data;
//     node* next;
//     node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// // Printing Linked list
// void printLL(node* &head){
//     node* temp = head;
//     while (temp != NULL){
//         cout<< temp->data<< " ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// void sortList(node *head){
//     int zerocount = 0;
//     int onecount = 0;
//     int twocount = 0;
//     node* temp = head;
//     while(temp != NULL){
//         if(temp->data == 0)
//             zerocount++;
//         else if(temp->data == 1)
//             onecount++;
//         else if(temp->data == 2)
//             twocount++;
        
//         temp = temp->next;
//     }

//     temp = head;
//     while(temp != NULL && zerocount){
//         temp->data = 0;
//         temp = temp->next;
//         zerocount--;
//     }
//     while(temp != NULL && onecount){
//         temp->data = 1;
//         temp = temp->next;
//         onecount--;
//     }
//     while(temp != NULL && twocount){
//         temp->data = 2;
//         temp = temp->next;
//         twocount--;
//     }
// }
// int main(){
//     node* head = new node(1);
//     head->next = new node(2);
//     head->next->next = new node(0);
//     head->next->next->next = new node(2);
//     head->next->next->next->next = new node(1); 
//     head->next->next->next->next->next = new node(0);
//     head->next->next->next->next->next->next = new node(2);

//     printLL(head);
//     cout<<"Linked list ater sorting:"<<endl;
//     sortList(head);
//     printLL(head);
//     return 0;
// }




// // O(n) O(1) not eassy
// #include<bits/stdc++.h>
// using namespace std;
// class node {
// public:
//     int data;
//     node* next;
//     node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// // Printing Linked list
// void printLL(node* &head){
//     node* temp = head;
//     while (temp != NULL){
//         cout<< temp->data<< " ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// node* sortList(node *head) {
//     node* nodetail0 = NULL;
//     node* nodetail1 = NULL;
//     node* nodetail2 = NULL;

//     node* nodehead0 = NULL;
//     node* nodehead1 = NULL;
//     node* nodehead2 = NULL;

//     while(head != NULL) {
//         node* current = head;
//         head = head->next;
//         current->next = NULL;

//         if(current->data == 0) {
//             if(nodetail0 == NULL)
//                 nodehead0 = current;
//             else
//                 nodetail0->next = current;
//             nodetail0 = current;
//         }
//         else if(current->data == 1) {
//             if(nodetail1 == NULL)
//                 nodehead1 = current;
//             else
//                 nodetail1->next = current;
//             nodetail1 = current;
//         }
//         else {
//             if(nodetail2 == NULL)
//                 nodehead2 = current;
//             else
//                 nodetail2->next = current;
//             nodetail2 = current;
//         }
//     }

//     // Connect the three sublists
//     if(nodetail0) nodetail0->next = nodehead1;
//     else nodehead0 = nodehead1;

//     if(nodetail1) nodetail1->next = nodehead2;

//     if (nodehead0) return nodehead0;
//     if (nodehead1) return nodehead1;
//     return nodehead2;
    
// }

// int main(){
//     node* head = new node(1);
//     head->next = new node(2);
//     head->next->next = new node(0);
//     head->next->next->next = new node(2);
//     head->next->next->next->next = new node(1); 
//     head->next->next->next->next->next = new node(0);
//     head->next->next->next->next->next->next = new node(2);

//     printLL(head);
//     cout<<"Linked list ater sorting:"<<endl;
//     head = sortList(head);
//     printLL(head);
//     return 0;
// }


// O(n) O(1) eassy version
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

void insertAtTail(node* &tail, node* curr) {
    tail -> next = curr;
    tail = curr;
}

node* sortList(node *head){
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    node* curr = head;


    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        int value = curr -> data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    // Connect the three sublists
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        // 1s list -> empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // setup head
    head = zeroHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1); 
    head->next->next->next->next->next = new node(0);
    head->next->next->next->next->next->next = new node(2);

    printLL(head);
    cout<<"Linked list ater sorting:"<<endl;
    head = sortList(head);
    printLL(head);
    return 0;
}