#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    // vector<int> arr = {1,2,3,-2,5};
    vector<int> arr = {-7,-8,-16,-4,-8,-5,-7,-11,-10,-12,-4,-6,-4,-16,-10};
    int n = arr.size();
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        maxsum = max(sum,maxsum);
    }
    cout<<maxsum<<endl;
    return 0;
}