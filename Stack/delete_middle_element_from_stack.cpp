#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int count, int size) {
   if(count == size/2 - 1) {
      inputStack.pop();
      return ;
   }

   int  num = inputStack.top();
   inputStack.pop();

   // Recursive call
   solve(inputStack,count+1,size);
   
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count = 0;
   solve(inputStack,count,N);
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
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.push(x);
    }
    
    cout << "Stack before deleting middle element:\n";
    printStack(s);
    
    deleteMiddle(s, n);
    
    cout << "Stack after deleting middle element:\n";
    printStack(s);
    return 0;
}