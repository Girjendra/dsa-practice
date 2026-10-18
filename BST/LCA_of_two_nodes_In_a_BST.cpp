#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
        int data;
        node *left, *right;
        node(int x) : data(x), left(NULL), right(NULL) {}
};




// TC = O(n)
// SC = O(n)
node* LCAinaBST(node *root, node *P, node *Q)
{
    if(!root)
        return NULL;

    if(root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);
    
    if(root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    return root;
}





// TC = O(n)
// SC = O(1)
node* LCAinaBST(node *root, node *P, node *Q)
{
    while(root) {
        if(root->data < P->data && root->data < Q->data)
            root = LCAinaBST(root->right, P, Q);
        else if(root->data > P->data && root->data > Q->data)
            root = LCAinaBST(root->left, P, Q);
        else
            return root;
    }
}