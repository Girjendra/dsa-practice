/*
Floyd's Cycle Detection Algorithm, also known as the
Tortoise and Hare algorithm, is used to detect a loop in a
linked list. It uses two pointers that move at different speeds:
->> Slow pointer (tortoise) moves one step at a time.
->> Fast pointer (hare) moves two steps at a time.

If there's a cycle, the two pointers will eventually meet inside
the cycle. If there's no cycle, the fast pointer will reach the end of the list.
*/

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

// Floyd’s Cycle Detection Algorithm
bool hasCycle(node* head) {
    if(head == NULL)
        return false;

    node *slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next;
        if(fast->next)
            fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            return true;           // Cycle detected
    }
    return false;                  // No cycle
}

int main(){
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5); 
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle detected in the linked list.\n";
    else
        cout << "No cycle in the linked list.\n";
    return 0;
}