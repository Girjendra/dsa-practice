#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // vector<int> arr = {2, 4, 1, 7, 5, 0};
    vector<int> arr = {3,2,1};
    int n = arr.size();

    int index1 = -1;
    for (int i = n-1; i>0; i--){
        if(arr[i-1]<arr[i]){
            index1 = i-1;
            break;
        }
    }

    if(index1 == -1) {
    reverse(arr.begin(), arr.end());
    }
    else{
        int index2 = -1;
        for (int i = n-1; i>=0; i--){
            if(arr[i]>arr[index1]){
                index2 = i;
                break;
            }
        }
    
        swap(arr[index1], arr[index2]);

        int start = index1+1;
        int end = n-1;
        while(start<end){
            swap(arr[start], arr[end]);
            start++;
            end--;     
        }

    }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    // vector<int> arr = {3,2,1};
    int n = arr.size();

    next_permutation(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}