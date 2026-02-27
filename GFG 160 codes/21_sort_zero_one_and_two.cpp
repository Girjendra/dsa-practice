// #include<iostream>
// #include<vector>
// using namespace std;
// void sort012(int arr[], int n) {

//     int i = 0;
//     int count1 = 0;
//     int count2 = 0;
//     int count3 = 0;

//     while(i<n){
//         if(arr[i]==0)
//             count1++;
//         if(arr[i]==1)
//             count2++;      
//         if(arr[i]==2)
//             count3++;
//         i++;
//    }
//    i = 0;
//    while(i < n){
//         if(count1) {
//             arr[i++] = 0;
//             count1--;
//         }
//         else if(count2) {
//             arr[i++] = 1;
//             count2--;
//         }
//         else if(count3) {
//             arr[i++] = 2;
//             count3--;
//         }
//     }
// }
// int main(){
//     int arr[12] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
//     sort012(arr,12);
//     for(int it:arr){
//         cout<<it<<" ";
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[12] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sort(arr,arr+12);
    for(int it:arr){
        cout<<it<<" ";
    }
    return 0;
}