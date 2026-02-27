#include<iostream>
#include<vector>
using namespace std;
int main(){
        vector<int> arr = {1,4,3,6,4,7,4};
        int n = arr.size();
        for(int i=0;i<n/2;i++){
            swap(arr[i],arr[n-1-i]);
        }
        for(int it:arr){
            cout<<it<<" ";
        }
    return 0;
}