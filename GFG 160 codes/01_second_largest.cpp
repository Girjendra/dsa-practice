#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();

    int max = -1;
    for(int j=0;j<n;j++){
        if(max<arr[j]){
            max = arr[j];
        }
    }
    int a= max; max = -1;
    for(int j=0;j<n;j++){
        if(max<arr[j] && arr[j]<a){
            max = arr[j];
        } 
    }
    cout<<max<<endl;
    return 0;
}