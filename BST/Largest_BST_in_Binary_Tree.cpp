#include<bits\stdc++.h>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(TreeNode* root, int &ans) {
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curNode;
    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = max(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        curNode.isBST = true;
    else
        curNode.isBST = false;

    if(curNode.isBST)
        ans = max(ans, curNode.size);
    
    return curNode;
}

int largestBST(TreeNode * root){
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}