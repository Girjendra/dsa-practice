#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
        int data;
        node *left, *right;
        node(int x) : data(x), left(NULL), right(NULL) {}
};


void inorder(node* root, vector<int>& res) {
    if(root == NULL)
        return ;

    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}


// TC = O(n)
// SC = O(n)
// creating BST from inorder
node* makeBST(int st, int end,vector<int>& res) {
    if(st > end)
        return NULL;

    int mid = st + (end - st) / 2;
    node* root = new node(res[mid]);

    root->left = makeBST(st, mid - 1, res);
    root->right = makeBST(mid + 1, end, res);

    return root;
}


node* balancedBst(node* root) {
    vector<int> res;
    inorder(root, res);

    return makeBST(0, res.size() - 1, res);
}