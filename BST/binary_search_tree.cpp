#include<iostream>
#include<queue>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};

// To print level order traversal
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

// To create BST using recursion
node* insertroot(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    if(data < root->data){
        root->left = insertroot(root->left, data);
    }
    else {
        root->right = insertroot(root->right, data);
    }
    
    return root;
}

void createtree(node* &root) { 
    cout << "Enter the data to create BTS:\n";
    int data;
    cin >> data;
    while(data != -1) {
        root = insertroot(root, data);
        cin >> data;
    }
}

// Search in BTS using iterative way
bool searchInBSTiterative(node* root, int x) {
    node* temp  = root;
    while(temp) {
        if(temp->data == x)
            return true;

        if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

// Search in BTS using recursion
bool searchInBSTrecursion(node* root, int x) {
        if(root == NULL)
            return false;

        if(root->data == x)
            return true;
    
        if(x < root->data)
            return searchInBSTrecursion(root->left, x);
        else
            return searchInBSTrecursion(root->right, x);
}


// TO find smallest element in BST
int find_smallest(node* root) {
    if(root == NULL)
        return -1;

    node* temp = root;
    while(temp->left)
        temp = temp->left;

    return temp->data;
} 

// TO find largest element in BST
int find_Largest(node* root) {
    if(root == NULL)
        return -1;

    node* temp = root;
    while(temp->right)
        temp = temp->right;
    
        return temp->data;
} 

// Inorder successor
node* inordersuccessor(node* root, int data) {
    node* successor = NULL;
    while(root) {
        if(data < root->data) {
            successor = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return successor;
}

// Inorder predecessor
node* inorderpredecessor(node* root, int data) {
    node* predecessor = NULL;
    while(root) {
        if(data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return predecessor;
}

// To Delete from BTS
node* deletefromBTS(node* root, int data) {
    if(root == NULL)
        return root;
    
    if(root->data == data) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child
        if(root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL) {
            node* temp = root->right;;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = find_smallest(root->right);
            root->data = mini;
            root->right = deletefromBTS(root->right, mini);
            return root;
        }
    }
    else if(root->data < data) {
        root->right = deletefromBTS(root->right, data);
        return root;
    }
    else {
        root->left = deletefromBTS(root->left, data);
        return root;
    }
}

int main(){
    node* root = NULL;
    createtree(root); // 8 7 11 5 9 13 3 6 12 14 2 4 -1

    // To level Order traversal
    levelOrdertraversal(root);
    
    cout << "Searchng in BST:" << searchInBSTiterative(root, 7) << endl;
    
    cout << "Smallest element : " << find_smallest(root) << endl;
    cout << "Largest element : " << find_Largest(root) << endl;

    cout << "successor of 6 :" << inordersuccessor(root, 6)->data << endl;
    cout << "successor of 6 :" << inorderpredecessor(root, 6)->data << endl;
    
    root = deletefromBTS(root, 7);
    levelOrdertraversal(root);
    return 0;
}