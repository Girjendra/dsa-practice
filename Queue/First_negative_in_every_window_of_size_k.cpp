/*
Given an array arr[]  and a positive integer k, find the first negative integer
for each and every window(contiguous subarray) of size k.
Note: If a window does not contain a negative integer, then return 0 for that window.
*/
#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int size = arr.size();
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0)
                dq.push_back(i);
        }
        
        if(!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
            
        for(int i = k; i < size; i++){
            
            if(!dq.empty() && i - dq.front() >= k)
                dq.pop_front();
            
            if(arr[i] < 0)
                dq.push_back(i);
                
            if(!dq.empty())
                ans.push_back(arr[dq.front()]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
