#include <bits/stdc++.h> 
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};

// TC = O(n)
// SC = O(h) in avg
// SC = O(n) in worst
// To check valid BST
bool isBSTtree(node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = isBSTtree(root->left, min, root->data);
        bool right = isBSTtree(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

bool validateBST(node* root) {
    return isBSTtree(root, INT_MIN, INT_MAX);
}