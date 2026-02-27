#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    static int size;
    static int index;

    // Constructor
    node(int elem) {
        data = elem;
        next = NULL;
    }

    //Distructor
    ~node() {}
};

// To push elements
void push(node* &head,int elem) { 
    node::index++;
    if(node::index >= node::size) {
        cout<<"Stack overflow"<<endl;
        node::index--;
        return ;
    }

    node* newnode = new node(elem);
    newnode->next = head;
    head = newnode;
    return ;
}

// To get top element
int top(node* head) {
    if(node::index >= 0 && head != NULL) {
        return head->data;
    }
    else {
        cout<<"stack is empty"<<endl;
        return -1;
    }
}

// To pop, top element
void pop(node* &head) {
    if(node::index < 0 || head == NULL) {
        cout << "Stack underflow" << endl;
        return;
    }

    node::index--;

    node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

// To check stack is empty or not
bool empty() {
    if(node::index >= 0)
        return false;
    else
        return true;
}

// To get size of stazk
int Size() {
    return node::index+1;
}

int node::size;
int node::index;

void getsize() {
    cout<<"Enter the size of stack: ";
    // cin>>node::size;
    node::size = 6;
    node::index = -1;
    cout<<node::size<<endl;
    cout<<node::index<<endl;
}


int main() {
    getsize();
    node* head = NULL;

    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);
    push(head,6);

    cout<<node::index<<endl;

    cout <<"Top element: " << top(head) << endl;
    pop(head);

    cout <<"Top element: " << top(head) << endl;
    cout <<"Size:" << Size() << endl;
    cout <<"is stack empty: " <<empty() << endl;

    pop(head);
    cout <<"Top element: " << top(head) << endl;

    pop(head);
    cout <<"Top element: " << top(head) << endl;

    pop(head);
    cout <<"Top element: " << top(head) << endl;

    pop(head);
    cout <<"Top element: " << top(head) << endl;
    pop(head);

    cout <<"Top element: " << top(head) << endl;

    return 0;
}