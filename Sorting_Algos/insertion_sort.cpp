#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int index = i;
        if(arr[i]<arr[i-1]){
            while (arr[index]<arr[index-1]&&index>=1){
                swap(arr[index],arr[index-1]);
                index--;
            }
        }
    }
}
int main(){
    vector<int> arr = {9,9,9,9,4,5,0,0,0,6,2,8,3,1,9,5};
    insertion_sort(arr);
    for(int it:arr)
        cout<<it<<" ";
    return 0;
}