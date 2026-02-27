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
// void printLL(node* head){
//     node* temp = head;
//     while (temp != NULL){
//         cout<< temp->data<< " ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// node* sortTwoLists(node* first, node* second){
//     if(first == NULL)
//         return second;
//     if(second == NULL)
//         return first;
    
//     node* previous = NULL;
//     node* current = first;

//     while(current != NULL){
//         previous = current;
//         current = current->next;
//     }

//     previous->next = second;

//     vector<int> v;
//     current = first;
//     while(current != NULL){
//         v.push_back(current->data);
//         current = current->next;
//     }

//     sort(v.begin(),v.end());
    
//     int i=0;
//     current = first;
//     while(current != NULL){
//         current->data = v[i];
//         i++;
//         current = current->next;
//     }

//     return first;
// }

// int main(){
//     node* first = new node(1);
//     first->next = new node(3);
//     first->next->next = new node(3);
//     first->next->next->next = new node(5);
//     first->next->next->next->next = new node(7); 
//     first->next->next->next->next->next = new node(8);
//     first->next->next->next->next->next->next = new node(8);

//     node* second = new node(0);
//     second->next = new node(2);
//     second->next->next = new node(4);
//     second->next->next->next = new node(6);
//     second->next->next->next->next = new node(6); 
//     second->next->next->next->next->next = new node(7);
//     second->next->next->next->next->next->next = new node(9);

//     cout<<"First Linked list: "<<endl;
//     printLL(first);
//     cout<<"Second Linked list: "<<endl;
//     printLL(second);
    
//     first = sortTwoLists(first,second);
//     cout<<"Merged Linked list: "<<endl;
//     printLL(first);
//     return 0;
// }





// O(n) O(1)
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
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

node* mergelists(node* first, node* second){

    if(first->next == NULL){
        first->next = second;
        return first;
    }

    node* cur1 = first;
    node* next1 = cur1->next;
    node* cur2 = second;
    node* next2 = cur2->next;

    while(next1 != NULL && cur2 != NULL){
        int elem = cur2->data;

        // Node can be added
        if(cur1->data <= elem && elem <= next1->data){
            // Add node in between the first list
            cur1->next = cur2;
            next2 = cur2->next;
            cur2->next = next1;

            // Update the pointers
            cur1 = cur2;
            cur2 = next2;
        }
        // Node can not be added
        else{
            // Move forward to cur1 and next1
            cur1 = next1;
            next1 = next1->next;

            // if first list is ended
            if(next1 == NULL){
                cur1->next = cur2;
                return first;
            }
        }
    }
    return first;
}



node* sortTwoLists(node* first, node* second){

    // if first list is empty 
    if(first == NULL)
        return second;

    // if second list is empty
    if(second == NULL)
        return first;
    
    if(first->data < second->data)
        return mergelists(first,second);
    else
        return mergelists(second,first);
}

int main(){
    node* first = new node(1);
    first->next = new node(3);
    first->next->next = new node(3);
    first->next->next->next = new node(5);
    first->next->next->next->next = new node(7); 
    first->next->next->next->next->next = new node(8);
    first->next->next->next->next->next->next = new node(8);

    node* second = new node(0);
    second->next = new node(2);
    second->next->next = new node(4);
    second->next->next->next = new node(6);
    second->next->next->next->next = new node(6); 
    second->next->next->next->next->next = new node(7);
    second->next->next->next->next->next->next = new node(9);

    cout<<"First Linked list: "<<endl;
    printLL(first);
    cout<<"Second Linked list: "<<endl;
    printLL(second);
    
    first = sortTwoLists(first,second);
    cout<<"Merged Linked list: "<<endl;
    printLL(first);
    return 0;
}