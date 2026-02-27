/*
Given a binary matrix mat[][] of size n * m. Find the maximum area
of a rectangle formed only of 1s in the given matrix.
*/

// O(n*m) O(m)
#include<bits/stdc++.h>
using namespace std;

// To find next smaller element of each element
vector<int> nextsmallerelem(vector<int> arr,int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--) {
        int elem = arr[i];
        while(st.top() != -1 && arr[st.top()] >= elem) {
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

// To find previous smaller element of each element
vector<int> prevsmallerelem(vector<int> arr,int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++) {
        int elem = arr[i];
        while(st.top() != -1 && arr[st.top()] >= elem) {
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

// To find largest area rowwise
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextsmallerelem(heights,n);

    vector<int> prev(n);
    prev = prevsmallerelem(heights,n);

    int area = INT_MIN;
    
    for(int i=0;i<n;i++) {
        int l = heights[i];
        
        if(next[i] == -1) 
            next[i] = n;

        int b = next[i] -prev[i] - 1;

        int newarea = l*b;
        
        area = max(newarea,area);
    }
    return area;
}

// To find maximum area in a vector
int maxArea(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxarea = largestRectangleArea(mat[0]);
    
    for(int i=1;i<n;i++) {
        
        for(int j=0;j<m;j++) {
            if(mat[i][j] != 0) {
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
            else {
                mat[i][j] = 0;
            }
        }    
        maxarea = max(maxarea,largestRectangleArea(mat[i]));
    }
    return maxarea;
}

int main() {
    vector<vector<vector<int>>> test_cases = {
        {
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0}
        },
        {
            {1, 0, 1, 0, 0},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0}
        },
        {
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    for (int i = 0; i < test_cases.size(); i++) {
        vector<vector<int>> mat = test_cases[i];
        cout << "Test case " << i + 1 << ": Maximum rectangle area = " << maxArea(mat) << endl;
    }

    return 0;
}