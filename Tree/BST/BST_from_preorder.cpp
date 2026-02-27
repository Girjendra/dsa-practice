#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
        int data;
        node *left, *right;
        node(int x) : data(x), left(NULL), right(NULL) {}
};



// TC = O(n*n)
// SC = O(1)
node* solve(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }

    if(data < root->data) {
        root->left = solve(root->left, data);
    }
    else{
        root->right = solve(root->right, data);
    }
    return root;
}

void createtree(node*& root, vector<int>& preorder) {
    int size = preorder.size();
    for(int i = 0; i < size; i++) {
        root = solve(root, preorder[i]);
    }
}

node* preorderToBST(vector<int> &preorder) {
    node* root = NULL;
    createtree(root, preorder);
    return root;
}




// TC = O(n)
// SC = O(1)
node* solve(vector<int>& preorder, int mini, int maxi, int &i) {
    if(i >= preorder.size())
        return NULL;

    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    node* root = new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini,maxi, i);
}