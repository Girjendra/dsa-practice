/*
Given the root of a binary tree, flatten the tree into a "Linked list":
The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/
#include<iostream>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};

void flatten(node *root) {
    node* cur = root;
    while(cur != NULL) {
        if(cur->left != NULL) {
            node* pre = cur->left;
            while(pre->right != NULL) {
                pre = pre->right;
            }
            
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
    
}