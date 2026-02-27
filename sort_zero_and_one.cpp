#include<iostream>
using namespace std;
void sortOne(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right) {
            left++;
        }

        while (arr[right] == 1 && left < right) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main(){
    int arr[12] = {1,0,1,0,0,1,0,1,1,0,0,1};
    sortOne(arr,12);
    for(int it:arr){
        cout<<it<<" ";
    }
    return 0;
}