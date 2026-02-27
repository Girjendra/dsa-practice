#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // vector<int> arr = {1, 5, 8, 10};
    // int k = 2; // 5
    vector<int> arr = {3, 9, 12, 16, 20};
    int k = 3; // 11

    int n = arr.size();

    sort(arr.begin(),arr.end());
    int initial_diff = arr[n-1] - arr[0];
    
    int Min = arr[0]+k;
    int Max = arr[n-1]-k;
    for(int i=0;i<n;i++){
        if((arr[i]-k)<0)
        continue;
        int minhight = min(Min,arr[i]-k);
        int maxhight = max(Max,arr[i-1]+k);
        
        initial_diff = min(initial_diff,maxhight-minhight);
    }
    cout<<initial_diff<<endl;
return 0;
}