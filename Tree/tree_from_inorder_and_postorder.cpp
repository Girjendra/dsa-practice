#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* solve(vector<int> in, vector<int> post, map<int,int> &mymap, int &index, int instart, int inend, int size) {
    if(index < 0 || instart > inend){
        return NULL;
    }
    int elem = post[index--];
    Node* root = new Node(elem);
    int position = mymap[elem];
    
    root->right = solve(in, post, mymap, index, position + 1, inend, size);
    root->left = solve(in, post, mymap, index, instart, position - 1, size);
    
    return root;
}

void creatingmap(map<int,int> &mymap, vector<int> &in, int n) {
    for(int i = 0; i < n; i++){
        mymap[in[i]] = i;
    }
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = postorder.size();
    int inorderindex = n - 1;
    map<int,int> mymap;
    creatingmap(mymap, inorder, n);
    Node* ans = solve(inorder, postorder, mymap, inorderindex, 0, n - 1, n);
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
    vector<int> postorder = {9, 15, 7, 20, 3};
    Node* root = buildTree(inorder, postorder);

    cout << endl << "Inorder traversal:" << endl;
    inorder_iteratively(root);
    return 0;
}