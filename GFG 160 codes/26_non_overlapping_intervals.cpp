#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    int minRemoval(vector<vector<int>> &intervals) {
        int count = 0; 
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        
        int end = intervals[0][1];
        int n = intervals.size();
        for(int i=1;i<n;i++){
            
            if(intervals[i][0]<end){
                count++;
                end = min(intervals[i][1],end);
            }
            else{
                end = intervals[i][1];
            }
            
        }
        return count;
    }
int main() {
    vector<vector<int> > intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << minRemoval(intervals) << endl;
}