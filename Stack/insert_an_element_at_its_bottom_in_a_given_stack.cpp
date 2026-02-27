#include <bits/stdc++.h>
using namespace std;
void solve(stack<int>& myStack, int x) {
    if(myStack.empty()) {
        myStack.push(x);
        return ;
    }

    int num = myStack.top();
    myStack.pop();

    // Recursive call
    solve(myStack , x);
    
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack , x);
    return myStack;
}

// Print the stack
void printStack(stack<int> s) {
    vector<int> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }

    for (int i=temp.size()-1;i>=0;i--) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test case 1
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    int x1 = 0;

    cout << "Test case 1: " <<endl;
    cout << "Element to insert: " << x1 <<endl;
    cout << "Stack before inserting element:\n";
    printStack(s1);
    
    stack<int> res1 = pushAtBottom(s1, x1);
    
    cout << "Stack after inserting element:\n";
    printStack(s1);
    cout<<endl;

    // Test case 2
    stack<int> s2;
    s2.push(10);
    s2.push(20);
    int x2 = 5;

    cout << "Test case 2: " <<endl;
    cout << "Element to insert: " << x2 <<endl;
    cout << "Stack before inserting element:\n";
    printStack(s2);
    
    stack<int> res2 = pushAtBottom(s2, x2);
    
    cout << "Stack after inserting element:\n";
    printStack(s2);
    cout<<endl;

    // Test case 3
    stack<int> s3;
    int x3 = 99;

    cout << "Test case 3: " <<endl;
    cout << "Element to insert: " << x3 <<endl;
    cout << "Stack before inserting element:\n";
    printStack(s3);
    
    stack<int> res3 = pushAtBottom(s3, x3);
    
    cout << "Stack after inserting element:\n";
    printStack(s3);
    cout<<endl;

    return 0;
}