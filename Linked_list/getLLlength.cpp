#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

int getLength(Node* head) {
    if (!head)
        return 0;
    return 1 + getLength(head->next);
}