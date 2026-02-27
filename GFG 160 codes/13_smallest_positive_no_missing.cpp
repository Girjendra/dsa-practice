#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // vector<int> arr = {2, -3, 4, 1, 1, 7};
    // vector<int> arr = {5, 3, 2, 5, 1};
    // vector<int> arr = {-8, 0, -1, -4, -3};
    vector<int> arr = {0};
    int n = arr.size();
    int min = 1;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]>0&&arr[i]==min){
            min = arr[i]+1;
        }
    }
    cout<<min<<endl;
    return 0;
}