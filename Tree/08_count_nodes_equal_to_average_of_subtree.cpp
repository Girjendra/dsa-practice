/*
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
*/
#include<iostream>
using namespace std;





//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// TC : O(n), SC : O(h)
class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans) {
        if(!root)
            return {0, 0};

        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);
        
        int tv = left.first + right.first + root->val;
        int tc = left.second + right.second + 1;

        if(root->val == (tv / tc))
            ans++;

        return {tv, tc};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};