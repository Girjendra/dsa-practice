/*
Design a data structure to implement ‘N’ stacks using a single array of
size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the
element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack
is empty, otherwise, returns the popped element.
*/

// O(1) O(n+s)
#include <bits/stdc++.h>
using namespace std;
class NStack{
    int* arr;
    int* top;
    int* next;

    int n,s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }

        // next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        // Update last index value to -1
        next[s-1] = -1;

        // initialise freeapot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){

        // check overflow condition
        if(freespot == -1) {
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // update net
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        // insert element into array
        arr[index] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){
        
        // check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }

        // find index
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main() {

    // Create 3 stacks in an array of size 10
    NStack st(3, 10);

    // Multiple operations on different stacks
    cout << "Push 10 to stack 1: " << st.push(10, 1) << endl; // true
    cout << "Push 20 to stack 2: " << st.push(20, 2) << endl; // true
    cout << "Push 30 to stack 3: " << st.push(30, 3) << endl; // true
    cout << "Push 40 to stack 1: " << st.push(40, 1) << endl; // true
    cout << "Push 50 to stack 2: " << st.push(50, 2) << endl; // true

    cout << "Pop from stack 1: " << st.pop(1) << endl; // 40
    cout << "Pop from stack 2: " << st.pop(2) << endl; // 50
    cout << "Push 60 to stack 3: " << st.push(60, 3) << endl; // true
    cout << "Pop from stack 3: " << st.pop(3) << endl; // 60
    cout << "Pop from stack 3: " << st.pop(3) << endl; // 30
    cout << "Pop from stack 1: " << st.pop(1) << endl; // 10
    cout << "Pop from stack 2: " << st.pop(2) << endl; // 20
    cout << "Pop from stack 1: " << st.pop(1) << endl; // -1 (already popped)


    // // Create 5 stacks in an array of size 10
    // NStack st(5, 10);

    // // Multiple operations on different stacks
    // cout << "Push 10 to stack 1: " << st.push(10, 1) << endl; // true
    // cout << "Push 20 to stack 2: " << st.push(20, 2) << endl; // true
    // cout << "Push 30 to stack 3: " << st.push(30, 3) << endl; // true
    // cout << "Push 40 to stack 4: " << st.push(40, 4) << endl; // true
    // cout << "Push 50 to stack 5: " << st.push(50, 5) << endl; // true

    // cout << "Pop from stack 1: " << st.pop(1) << endl; // 10
    // cout << "Pop from stack 2: " << st.pop(2) << endl; // 20
    // cout << "Push 60 to stack 5: " << st.push(60, 5) << endl; // true
    // cout << "Pop from stack 5: " << st.pop(5) << endl; // 60
    // cout << "Pop from stack 5: " << st.pop(5) << endl; // 50
    // cout << "Pop from stack 3: " << st.pop(3) << endl; // 30
    // cout << "Pop from stack 4: " << st.pop(4) << endl; // 40
    // cout << "Pop from stack 1: " << st.pop(1) << endl; // -1 (already popped)

    return 0;
}
