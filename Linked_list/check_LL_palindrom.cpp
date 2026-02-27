// // O(n) O(n) eassy version
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

// bool isPalindrome(node* head){
        
//     vector<int> v;
//     // store all node data in a vector
//     while(head != NULL){
//         v.push_back(head->data);
//         head = head->next;
//     }
        
//     // Now check wether vector is palindrome or not 
//     int i = 0;
//     int j = v.size() - 1;
//     while(i <= j){
//         if(v[i] != v[j])
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }

// int main(){
//     node* head = new node(1);
//     head->next = new node(2);
//     head->next->next = new node(0);
//     head->next->next->next = new node(2);
//     head->next->next->next->next = new node(0); 
//     head->next->next->next->next->next = new node(2);
//     head->next->next->next->next->next->next = new node(1);

//     printLL(head);
//     if(isPalindrome(head))
//         cout<<"Linked list is palindrom"<<endl;
//     else
//         cout<<"Linked list is not palindrom"<<endl;
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
void printLL(node* &head){
    node* temp = head;
    while (temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

// Reverse the Linked list
node* reverseLinkedList(node* &head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* previous = NULL;
    node* current = head;
    node* forward = head;
    while (current != NULL) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

// findmiddle pointer
node *findMiddle(node *head) {
    // 1 node
    if(head == NULL || head->next == NULL)
        return head;
    
    // 2 Node
    if(head->next->next == NULL)
        return head->next;

    node* fast = head->next;
    node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(node* head){

    // Step 1: Find middle node
    node* middle = findMiddle(head);

    // Step 2: Reverse second half
    node* temp = middle->next;
    middle->next = reverseLinkedList(temp);

    // Step 3: Compare two halves
    node* head1 = head;
    node* head2 = middle->next;
    bool flag = true;
    while(head2 != NULL){
        if(head1->data != head2->data)
            flag = false;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // Step 4: Restore the second half
    temp = middle->next;
    middle->next = reverseLinkedList(temp);

    return flag;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(0); 
    head->next->next->next->next->next = new node(2);
    head->next->next->next->next->next->next = new node(1);

    printLL(head);
    if(isPalindrome(head))
    cout<<"Linked list is palindrom"<<endl;
    else
    cout<<"Linked list is not palindrom"<<endl;
    printLL(head);
    return 0;
}