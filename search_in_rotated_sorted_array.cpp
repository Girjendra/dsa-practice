#include<iostream>
#include<vector>
using namespace std;
int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n-1;
    int mid =s+(e-s)/2;
    while (s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;  // or return e; both are same here
}

int binarysearch(vector<int>& arr,int start,int end ,int key){
    int mid = start + (end-start)/2;

    while (start<=end){
        if(key==arr[mid]){
            return mid;
        }

        if(key<arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int pivot = getPivot(arr,n);

    if(k>=arr[pivot]&&k<=arr[n-1])
        return binarysearch(arr,pivot,n-1,k);
    else
        return binarysearch(arr,0,pivot-1,k);
}
int main(){
    
    vector<int> arr  ={5,6,7,8,9,10,1,2,3};
    int k = 10;
    cout<<"Target value is found at index: "<<search(arr,arr.size(),k)<<endl;;
    return 0;
}