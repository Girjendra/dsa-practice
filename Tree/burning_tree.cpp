#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *createmapping(Node *root, int target, map<Node *, Node *> &parentMap)
{
    queue<Node *> q;
    q.push(root);
    parentMap[root] = NULL;
    Node *res = NULL;

    while (!q.empty())
    {

        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            parentMap[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            parentMap[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burntree(Node *tnode, map<Node *, Node *> &parentMap)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(tnode);
    visited[tnode] = true;

    int ans = 0;

    while (!q.empty())
    {

        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                flag = true;
            }

            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }

            if (parentMap[front] && !visited[parentMap[front]])
            {
                q.push(parentMap[front]);
                visited[parentMap[front]] = true;
                flag = true;
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> parentMap;
    Node *tnode = createmapping(root, target, parentMap);
    int ans = burntree(tnode, parentMap);
    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 6;
    cout << "Minimum time to burn the tree from target " << target << " is: " << minTime(root, target) << endl;
}