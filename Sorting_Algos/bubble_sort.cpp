// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {4,7,2,1,8,4,6,3,9,0};
//     int n = arr.size();
//     for (int i = 0; i < n; i++){
//         for (int j = 1; j < n-i; j++){
//             if(arr[j-1]>arr[j])
//                 swap(arr[j-1],arr[j]);
//         }
//     }
//     for(int it:arr)
//         cout<<it<<" ";
//     return 0;
// }


// Optimized
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {4,7,2,1,8,4,6,3,9,0};
//     int n = arr.size();
//     bool flag = false;
//     for (int i = 0; i < n; i++){
//         for (int j = 1; j < n-i; j++){
//             if(arr[j-1]>arr[j]){
//                 swap(arr[j-1],arr[j]);
//                 flag = true;
//             }
//         }
//         if(flag==false)
//             break;
//     }
//     for(int it:arr)
//         cout<<it<<" ";
//     return 0;
// }