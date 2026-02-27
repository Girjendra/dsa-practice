// #include<iostream>
// #include<vector>
// using namespace std;
// int getPivot(int arr[], int n){
//     int s = 0;
//     int e = n-1;
//     int mid =s+(e-s)/2;
//     while (s<e){
//         if(arr[mid]>=arr[0]){    // if array is not rotated then it will give wrong answers
//             s = mid+1;
//         }
//         else{
//             e = mid;
//         }
//         mid = s+(e-s)/2;
//     }
//     return s;  // or return e; both are same here
// }
// int main(){
//     int arr[5] = {3, 8, 10, 17, 1};   // here we are finding 1
//     cout << "Pivot is " << getPivot(arr, 5) << endl;
//     return 0;




#include<iostream>
#include<vector>
using namespace std;
int getPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid =s+(e-s)/2;
    while (s<e){
        if(arr[mid]>arr[e]){    // no worry wether array is rotated or not
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;  // or return e; both are same here
}
int main(){
    // int arr[5] = {3, 8, 10, 17, 1};   // here we are finding 1
    int arr[5] = {91,96};
    cout << "Pivot(minimum element index) is: " << getPivot(arr, 2) << endl;
    return 0;
}