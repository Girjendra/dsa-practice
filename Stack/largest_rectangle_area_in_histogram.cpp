/*
Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/



// // O(n*n) O(n)
// #include<bits/stdc++.h>
// using namespace std;

// // To find largest area
// int largestRectangleArea(vector<int>& heights) {
//     int maxarea = 0;
//     for(int i=0;i<heights.size();i++) {
//         int currentheight = heights[i];
//         int left = i;
//         int right = i;
//         while(left > 0 && heights[left - 1] >= currentheight)
//             left--;
            
//         while(right < heights.size() - 1 && heights[right + 1] >= currentheight)
//             right++;
        
//         int width = right-left+1;
//         maxarea = max(maxarea,width*currentheight);
//     }
//     return maxarea;
// }

// int main(){
//     vector<int> heights = {2,1,5,6,2,3};
//     // vector<int> heights = {2,4};

//     int maxarea = largestRectangleArea(heights);

//     cout<<"Largest rectangle area is: "<<maxarea<<endl;
//     return 0;
// }
// 




#include<bits/stdc++.h>
using namespace std;
// O(n) O(n)
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

// To find largest area
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

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    // vector<int> heights = {2,4};

    int maxarea = largestRectangleArea(heights);

    cout<<"Largest rectangle area is: "<<maxarea<<endl;
    return 0;
}