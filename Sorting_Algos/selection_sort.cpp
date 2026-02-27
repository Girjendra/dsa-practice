#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {3,5,3,7,8,4,5,2,1,0,8,4};
    // vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int n = arr.size();
    for(auto it: arr)
        cout<<it<<" ";
        
    for (int i = 0; i < n-1; i++){
        int minindex = i;
        bool flag = false;
        for (int j = i+1; j < n; j++){
            if(arr[minindex]>arr[j]){
                minindex = j;
                flag = true;
            }
        }
        if(flag==false){
            // cout<<i+23<<endl;
            break;
        }
        else
        swap(arr[i],arr[minindex]);
    }
    cout<<endl;
    for(auto it: arr)
        cout<<it<<" ";
    
    return 0;
}