// O(n*n) O(n)
#include <bits/stdc++.h>
using namespace std;

// To insert an element to its correct place
void solve(stack<int> &stack,int elem) {
	if(stack.empty() || elem >= stack.top()) {
		stack.push(elem);
		return ;
	}

	int num = stack.top();
	stack.pop();
		
	// Recursive call
	solve(stack,elem);

	stack.push(num);
}

// To sort the stack
void Sort(stack<int> &stack) {
	// Base case
	if(stack.empty())
		return ;

	int num = stack.top();
	stack.pop();

	// Recursive call to sort
	Sort(stack);

	// insert num to its correct place
	solve(stack,num);
}

// To sort the stack
void sortStack(stack<int> &stack){
	Sort(stack);
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
    stack<int> s;
    // Hardcoded values
    s.push(3);
    s.push(0);
    s.push(4);
    s.push(9);
    s.push(5);

    cout << "Stack before sorting: ";
    printStack(s);

    sortStack(s);

    cout << "Stack after sorting: ";
    printStack(s);

    return 0;
}

/*
Sort([5,9,4,0,3])
│
├── Sort([9,4,0,3])
│   ├── Sort([4,0,3])
│   │   ├── Sort([0,3])
│   │   │   ├── Sort([3])
│   │   │   │   ├── Sort([]) → base case
│   │   │   │   └── solve([], 3) → push 3
│   │   │   └── solve([3], 0)
│   │   │       ├── pop 3 → solve([], 0) → push 0 → push 3
│   │   └── solve([0,3], 4)
│   │       ├── 4 > top → push 4
│   └── solve([0,3,4], 9)
│       ├── 9 > top → push 9
└── solve([0,3,4,9], 5)
    ├── pop 9 → solve([0,3,4], 5)
    ├── 5 > top → push 5 → push 9

*/