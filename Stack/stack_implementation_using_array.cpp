#include<iostream>
using namespace std;
class stack {
    int* arr;
    int index;
    int size;
public:
    stack(int size) {
        this->size = size;
        index = -1;
        arr = new int[this->size];
    }

    // O(1)
    void push(int elem) {
        index++;
        if(index < size){
            arr[index] = elem;
        }
        else {
            cout<<"stack overflow"<<endl;
        }
    }

    // O(1)
    void pop() {
        if(index >= 0)
            index--;
        else
            cout<<"stack underflow"<<endl;
    }

    // O(1)
    int top() {
        if(index >= 0) {
            return arr[index];
        }
        else {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    // O(1)
    bool empty() {
        if(index >= 0)
            return false;
        else
            return true;
    }

    // O(1)
    int Size() {
        return index+1;
    }
};


int main(){
    stack st(6);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.top() << endl;
    st.pop();
    
    cout << st.top() << endl;
    cout << st.Size() << endl;
    cout <<st.empty() << endl;
    
    cout<<st.Size()<<endl;

    st.pop();
    cout << st.top() << endl;

    st.pop();
    cout << st.top() << endl;

    st.pop();
    cout << st.top() << endl;

    st.pop();
    cout << st.top() << endl;

    return 0;
}