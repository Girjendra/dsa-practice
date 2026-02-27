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
pair<int, int> predecessorSuccessor(node *root, int key) {
    if(root == NULL) 
        return {-1, -1};
    else if(root->left == NULL && root->right == NULL)
        return {-1, -1};
    
    vector<int> vec;
    node* cur = root;
    while(cur != NULL) {
        if(cur->left == NULL) {
            vec.push_back(cur->data);
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
                vec.push_back(cur->data);
                pred->right = NULL;
                cur = cur->right;
            }
        }
    }

    int st  = 0;
    int end = vec.size() - 1;
    int predecessor = -1, successor = -1;
    while(st <= end) {
        int mid = st + (end - st) / 2; 

        if (vec[mid] == key) {
            if (mid > 0) predecessor = vec[mid - 1];
            if (mid < vec.size() - 1) successor = vec[mid + 1];
            return {predecessor, successor};
        }
        
        if (vec[mid] < key) {
            predecessor = vec[mid];
            st = mid + 1;
        } 
        else {
            successor = vec[mid];
            end = mid - 1;
        }
    }
    return {predecessor, successor};
}






// TC = O(h)
// SC = O(1)
pair<node*, node*> findpredecessorSuccessor(node* root, int data) {
    node* pred = NULL;
    node* succ = NULL;

    node* temp = root;
    while(temp) {
        if(data > temp->data) {
            pred = temp;
            temp = temp->right;
        }
        else
            temp = temp->left;
    }

    temp = root;
    while(temp) {
        if(data < temp->data) {
            succ = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }

    return {pred, succ};
}

pair<int, int> predecessorSuccessor(node *root, int key) {
    
    pair<node*, node*> ans = findpredecessorSuccessor(root, key);
    node* pred = ans.first;
    node* succ = ans.second;

    if(pred == NULL && succ == NULL)
        return {-1, -1};
    else if(pred != NULL && succ != NULL)
        return {pred->data, succ->data};
    else if(pred != NULL && succ == NULL)
        return {pred->data, -1};
    else if(pred == NULL && succ != NULL)
        return {-1, succ->data};
}






// TC = O(n)
// SC = O(1)
pair<int, int> predecessorSuccessor(node *root, int key) {
    if(root == NULL) 
            return {-1, -1};
        else if(root->left == NULL && root->right == NULL)
            return {-1, -1};

    node* temp = root;
    int pred = - 1;
    int succ = - 1;
    while(temp && temp->data != key) {
        if(temp->data < key) {
            pred = temp->data;
            temp = temp->right;
        }
        else {
            succ = temp->data;
            temp = temp->left;
        }
    }

    if(temp != NULL) {
        node* left = temp->left;
        while (left) {
            pred = left->data;
            left = left->right;
        }
    }

    if(temp != NULL) {
        node* right = temp->right;
        while(right) {
            succ = right->data;
            right = right->left;
        }
    }

    return {pred, succ};
}