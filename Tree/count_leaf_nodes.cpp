#include<iostream>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};

void countleafs(node* root,int& count) {
    if(root == NULL) {
        return ;
    }

    countleafs(root->left, count);

    if(root->left == NULL && root->right == NULL) {
        count++;
    }

    countleafs(root->right, count);
}

int noOfLeafNodes(node* root){
    int count = 0;
    countleafs(root,count);
    return count;
}