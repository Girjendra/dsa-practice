#include<iostream>
using namespace std;
int elementsearch(int arr[],int size,int key){
    int start = 0;
    int end = size - 1;
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
int main(){
    int arr[7] = {1,3,5,6,7,9,10};
    int index = elementsearch(arr,7,7);
    if(index==-1)
        cout<<"Element not found"<<endl;
    else
        cout<<"Element found at index "<<index<<endl;
    return 0;
}