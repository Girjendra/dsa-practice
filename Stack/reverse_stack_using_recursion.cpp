// O(n*n) O(n)
#include<bits/stdc++.h>
using namespace std;

// To insert an element at bottom
void solve(stack<int> &stack ,int elem) {
    if(stack.empty()) {
        stack.push(elem);
        return ;
    }

    int num = stack.top();
    stack.pop();

    // Recursive call
    solve(stack,elem);
    
    stack.push(num);
}


// To insert an element at bottom
void pushatbottom(stack<int> &stack ,int elem) {
    solve(stack,elem);
}

// To reverse the stack
void Reverse(stack<int> &stack) {
    if(stack.empty()) {
        return ;
    }
    
    if(stack.size() == 1) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    Reverse(stack);

    pushatbottom(stack,num);
}

// To reverse the stack
void reverseStack(stack<int> &stack) {
    Reverse(stack);
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
    stack<int> st;
    // Hard coded values
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}

/*
Reverse([4,3,2,1])
│
├── Reverse([3,2,1])
│   │
│   ├── Reverse([2,1])
│   │   │
│   │   ├── Reverse([1])
│   │   │   │
│   │   │   └── Reverse([]) → base case
│   │   │
│   │   └── solve([], 1) → push 1
│   │
│   └── solve([1], 2)
│       ├── pop 1
│       └── solve([], 2) → push 2 → push 1
│
├── solve([2,1], 3)
│   ├── pop 1
│   ├── pop 2
│   └── solve([], 3) → push 3 → push 2 → push 1
│
└── solve([3,2,1], 4)
    ├── pop 1
    ├── pop 2
    ├── pop 3
    └── solve([], 4) → push 4 → push 3 → push 2 → push 1

*/