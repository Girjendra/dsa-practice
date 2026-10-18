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

node* flatten(node* root)
{
    vector<int> res;
    inorder(root, res);
    int n = res.size();

    node* newroot = new node(res[0]);
    node* cur = newroot;

    for(int i = 1; i < res.size(); i++) {
        node* temp = new node(res[i]);

        cur->left = NULL;
        cur->right = temp;
        cur = temp;
    }

    cur->left = NULL;
    cur->right = NULL;

    return newroot;
}