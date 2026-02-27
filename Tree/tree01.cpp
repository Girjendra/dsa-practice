#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};

// Creating a tree
node* createtree(node* root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the data to insert in left of " << data << endl;
    root->left = createtree(root->left);
    cout << "Enter the data to insert in right of " << data << endl;
    root->right = createtree(root->right);
    return root;
}

// Building tree from level order input
void buildtreefromlevelorder(node* &root) {
    cout << "Enter the data for root: ";
    int rootdata;
    cin >> rootdata;
    queue<node*> que;

    if(rootdata != -1) {
        root = new node(rootdata);
        que.push(root);
    }
    else
        return ;

    while(!que.empty()) {
        node* temp = que.front();
        que.pop();

        cout << "Enter left node for " << temp->data << ": ";
        int leftdata;
        cin >> leftdata;
        if(leftdata != -1) {
            temp->left = new node(leftdata);
            que.push(temp->left);
        }
        
        cout << "Enter right node for " << temp->data << ": ";
        int rightdata;
        cin >> rightdata;
        if(rightdata != -1) {
            temp->right = new node(rightdata);
            que.push(temp->right);
        }
    }
}

// Level Order Traversal
void levelOrdertraversal(node* root) {
    if(root == NULL) return ;

    cout << "Printing level order traversal: " << endl;
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;      // Last level is completely traversed
            if(!q.empty()) {
                q.push(NULL);  // Queue has still some child nodes
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Reverse Level Order Traversal
void reverselevelOrdertraversal(node* root) {
    if(root ==NULL) return ;

    queue<node*> q;
    stack<node*> st;

    q.push(root);
    q.push(NULL);

    st.push(root);
    st.push(NULL);


    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            st.push(NULL);
            if(!q.empty())
                q.push(NULL);
        }
        else {
            if(temp->right) {
                st.push(temp->right);
                q.push(temp->right);
            }
            if(temp->left) {
                st.push(temp->left);
                q.push(temp->left);
            }
        }
    }

    while (!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp == NULL)
            cout << endl;
        else
            cout << temp->data << " ";
    }
}

// Recursive inorder traversal
void inorder(node* root) { 
    if(root == NULL)
        return ;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}

// Recursive preorder traversal
void preorder(node* root) { 
    if(root == NULL)
        return ;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);    
}

// Recursive postorder traversal
void postorder(node* root) { 
    if(root == NULL)
        return ;

    postorder(root->left);
    postorder(root->right);    
    cout << root->data << " ";
}

// Iterative inorder traversal
void inorder_iteratively(node* root) { 
    stack<node*> st;
    node* cur = root;

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

// Iterative preorder traversal
void preorder_iteratively(node* root) {
    if(root == NULL)
        return ;

    stack<node*> st;
    st.push(root);
    
    while (!st.empty()) {
        node* cur = st.top();
        st.pop();

        cout << cur->data << " ";

        if( cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
    }
}

// Iterative postorder traversal
void postorder_iteratively(node* root) {
    if(root == NULL)
        return ;

    stack<node*> st1, st2;
    st1.push(root);
    
    while(!st1.empty()) {
        node* cur = st1.top();
        st1.pop();
        st2.push(cur);

        if(cur->left) st1.push(cur->left);
        if( cur->right) st1.push(cur->right);    
    }

    while(!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// Morris Inorder Traversal
void MorrisinOrder(node* root) {
    node* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            
            if(pred->right == NULL) {
                pred->right = curr;    // create thread
                curr = curr->left;
            }
            else {
                cout << curr->data << " ";
                pred->right = NULL;    // remove thread
                curr = curr->right;
            }
            
        }
    }
}

// Morris Preorder Traversal
void MorrispreOrder(node* root) {
    node* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            
            if(pred->right == NULL) {
                cout << curr->data << " "; // print before going left
                pred->right = curr;    // create thread
                curr = curr->left;
            }
            else {
                pred->right = NULL;    // remove thread
                curr = curr->right;
            }
            
        }
    }
}


int main(){
    node* root = NULL;

    // Create a tree 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 -1
    root = createtree(root);
    buildtreefromlevelorder(root);


    // To level Order traversal
    levelOrdertraversal(root);

    // To reverse level Order traversal
    // reverselevelOrdertraversal(root);

    // cout << endl << "Recursive Inorder traversal:" << endl;
    // inorder(root);
    
    // cout << endl << "Recursive Preorder traversal:" << endl;
    // preorder(root);
    
    // cout << endl << "Recursive Postorder traversal:" << endl;
    // postorder(root);
    

    // cout << endl << "Iterative Inorder traversal:" << endl;
    // inorder_iteratively(root);
    
    // cout << endl << "Iterative Preorder traversal:" << endl;
    // preorder_iteratively(root);
    
    // cout << endl << "Iterative Postorder traversal:" << endl;
    // postorder_iteratively(root);
    
    
    // cout << endl << "Morris Inorder traversal:" << endl;
    // MorrisinOrder(root);
    
    // cout << endl << "Morris preorder traversal:" << endl;
    // MorrispreOrder(root);

    return 0;
}