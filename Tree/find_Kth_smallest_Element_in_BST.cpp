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
// SC = O(1)
int inordermorris(node* root, int k) {
    node* cur = root;
    int i = 0;
    while(cur != NULL) {
        if(cur->left == NULL) {
            i++;
            if(i == k)
                return cur->data;
            cur = cur->right;
        }
        else {
            node* pred = cur->left;
            while(pred->right != NULL && pred->right != cur) {
                pred = pred->right;
            }

            if(pred->right == NULL) {
                pred->right = cur;
                cur = cur->left;
            }
            else {
                i++;
                if(i == k)
                    return cur->data;
                pred->right = NULL;
                cur = cur->right;
            }
        }
    }
    return -1;
}

// To find Kth smallest element in BST
int kthSmallest(node* root, int k) {
    return inordermorris(root, k);
}


// TC = O(n)
// SC = O(h)
int solve(node* root, int& i, int k) {
    if(root == NULL) {
        return -1;
    }

    int left = solve(root->left, i, k);

    if(left != -1) {
        return left;
    }

    i++;
    if(i == k) {
        return root->data;
    }

    return solve(root->right, i, k);
}

// To find Kth smallest element in BST
int kthSmallest(node* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}