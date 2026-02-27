// function Template for C++
#include <bits/stdc++.h> 
using namespace std;
// O(n) O(n)
class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        int size = q.size();
        vector<int> v(size);
        for(int i = size - 1; i >= 0; i--) {
            v[i] = q.front();
            q.pop();
        }
        
        queue<int> q2;
        
        for(int it:v) {
            q2.push(it);
        }
        
        return q2;
    }
};



// O(n) O(n)
class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        return q;
    }
};


// Using recursion
// O(n) O(n)
class Solution {
    void reverse(queue<int> &original, queue<int> &reversed) {
        if(original.empty())
            return;
        
        int elem = original.front();
        original.pop();
        reverse(original, reversed);
        reversed.push(elem);
    }
    
  public:
    queue<int> reverseQueue(queue<int> &q) {
        queue<int> result;
        reverse(q, result);
        return result;
    }
};
