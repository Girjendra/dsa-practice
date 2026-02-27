#include <iostream>
using namespace std;

class TwoStack {
    int size;
    int top1;
    int top2;
    int* arr;

public:

    // Constructor
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Destructor
    ~TwoStack() {
        delete[] arr;
    }

    // Push in stack 1
    void push1(int num) {
        if(top1 + 1 < top2) {
            top1++;
            arr[top1] = num;
        }
        else {
            // Overflow for stack1
        }
    }

    // Push in stack 2
    void push2(int num) {
        if(top1 + 1 < top2) {
            top2--;
            arr[top2] = num;
        }
        else {
            // Overflow for stack2
        }
    }

    // Pop from stack 1
    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    // Pop from stack 2
    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
};

int main() {
    TwoStack twoStack(3);

    twoStack.push1(2);  // pushing 2 in stack1
    twoStack.push1(4);  // pushing 4 in stack1
    twoStack.push1(3);  // pushing 3 in stack1
    twoStack.push2(5);  // no space left, do nothing

    cout << twoStack.pop2() << endl; // -1 (stack2 is empty)
    cout << twoStack.pop1() << endl; // 3
    twoStack.push2(6);               // push 6 in stack2
    cout << twoStack.pop2() << endl; // 6
    cout << twoStack.pop1() << endl; // 4
    twoStack.push2(7);               // push 7 in stack2

    return 0;
}
