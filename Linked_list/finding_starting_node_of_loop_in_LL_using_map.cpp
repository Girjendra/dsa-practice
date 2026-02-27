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

//Cycle Detection using map
bool hasCycle(node* head) {
    node* temp = head;

    map<node*,bool> visited;
    while (temp != NULL) {
        // Cycle detected
        if(visited[temp] == true){              
            cout<<"Starting node with node data: "<<temp->data<<endl;                
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;                   // No cycle
}

int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5); 
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next = head->next->next;

    if (hasCycle(head))
        cout << "Cycle detected in the linked list.\n";
    else
        cout << "No cycle in the linked list.\n";
    return 0;
}