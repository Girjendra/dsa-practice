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
bool twoSumInBST(node* root, int target) {
	vector<int> res;
    node* cur = root;
    while(cur != NULL) {
        if(cur->left == NULL) {
            res.push_back(cur->data);
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
                res.push_back(cur->data);
                pred->right = NULL;
                cur = cur->right;
            }
        } 
    }

    int i = 0;
    int j = res.size() - 1;
    while(i < j) {
        int sum = res[i] + res[j];
        if(sum == target) {
            return true;
        }

        if(sum < target)
            i++;
        else
            j--;
    }
    return false;
}