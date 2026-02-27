#include<iostream>
#include<cstring>
using namespace std;
int main(){

    int arr[10];
    // 0th way to initialize an array
    // int arr[10] = {0};      // array of zero's this doesn't work with non zero integers


    // 1st way to initialize an array
    // for(int& it:arr){
    //     cin>>it;
    // }


    // 2nd way to initialize an array only with 0 = 9,-1 = -1,255 = -1
    // memset(arr,-1, sizeof(arr));      // in both C and C++
  

    // 3rd way to initialize an array with any number
    // fill(arr, arr + 4, 23);    // Not in C

    // for(int it:arr){
    //     cout<<it<<" ";
    // }

    return 0;
}