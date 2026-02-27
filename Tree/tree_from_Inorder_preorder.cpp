#include <bits/stdc++.h>
using namespace std;
// Definition of the Node class
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* solve(vector<int> in, vector<int> post, map<int,int> &mymap, int &index, int instart, int inend, int size) {
    if(index >= size || instart > inend){
        return NULL;
    }
    int elem = post[index++];
    Node* root = new Node(elem);
    int position = mymap[elem];
    
    root->left = solve(in, post, mymap, index, instart, position - 1, size);
    root->right = solve(in, post, mymap, index, position + 1, inend, size);
    
    return root;
}

void creatingmap(map<int,int> &mymap, vector<int> &in, int n) {
    for(int i = 0; i < n; i++){
        mymap[in[i]] = i;
    }
}

// Function to build the tree from given inorder and preorder traversals
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    int postrderindex = 0;
    int n = preorder.size();
    map<int,int> mymap;
    creatingmap(mymap, inorder, n);
    Node* ans = solve(inorder, preorder, mymap, postrderindex, 0, n - 1, n);
    return ans;
}
    
void inorder_iteratively(Node* root) { 
    stack<Node*> st;
    Node* cur = root;

    while(cur != NULL || !st.empty()) {

        while(cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();

        cout << cur->data << " ";
        cur = cur->right;       
    }   
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Node* root = buildTree(inorder, preorder);

    cout << endl << "Inorder traversal:" << endl;
    inorder_iteratively(root);
    return 0;
}