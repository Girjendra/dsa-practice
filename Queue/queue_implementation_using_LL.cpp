#include<iostream>
using namespace std;
class Node {
public:
    static int size;
    int data;
    Node* next;
    
    // Contructor
    Node(int data) {
        this->data = data;
        next = NULL;
    }

    // Destructor
    ~Node() {}
};

//Defining static variable
int Node::size = 0;

// o(1)
//To Push elements in back
void Push(Node* &front, Node* &rear,int data) {
    Node* newnode = new Node(data);
    Node::size++;

    if(front == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

// o(1)
// To Pop elements from front
void Pop(Node* &front, Node* &rear) {
    if(front == NULL) {
        cout << "Queue underflow" << endl;
        return ;
    }
    else {
        Node* temp = front;
        front = front->next;
        delete temp;
        Node::size--;

        if(front == NULL) {  
            rear = NULL;  // Node is now empty
        }
    }
}

// o(1)
// To get size of current Node
int Size() {
    return Node::size;
}

// o(1)
// Checking if Node is empty
bool Empty() {
    return Node::size == 0;
}

// o(1)
// To get front element of Node
int Front(Node* &front) {
    if(front != NULL)
        return front->data;
    else{
        cout << "Node is empty" << endl;
        return -1;
    }
}

// o(1)
// To get last element of Node
int Rear(Node* &rear) {
    if(rear != NULL){
        return rear->data;
    }
    else {
        cout << "Node is empty" << endl;
        return -1;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    Push(front, rear, 10);
    Push(front, rear, 20);
    Push(front, rear, 30);

    cout << "Front: " << Front(front) << endl;   // Expected: Front: 10
    cout << "Rear: " << Rear(rear) << endl;      // Expected: Rear: 30
    cout << "Size: " << Size() << endl;          // Expected: Size: 3

    Pop(front, rear);

    cout << "After 1 pop, Front: " << Front(front) << endl; // Expected: Front: 20
    cout << "Size: " << Size() << endl;                     // Expected: Size: 2

    while (!Empty()) {
        Pop(front, rear);
    }

    cout << "Node empty: " << Empty() << endl;   // Expected: Node empty: 1 (true)

    return 0;
}