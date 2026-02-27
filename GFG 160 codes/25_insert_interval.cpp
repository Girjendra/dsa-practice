#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    
    for(int i=1;i<n;i++){
        
        vector<int>& last = res.back();
        vector<int>& cur = intervals[i];
        
        if(last[1]>=cur[0])
            last[1] = max(last[1],cur[1]);
        else
            res.push_back(cur);
    }
    return res;
}
int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
  	for (vector<int> interval: res) {
      	cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}