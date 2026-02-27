// // Rotate array from right by d positions
// better
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//         vector<int> arr = {1,4,6,2,7,3,9,4,};
//         int d = 4;

//         int n = arr.size();
//         d = d%n;
//         d = n-d;
//         reverse(arr.begin(),arr.begin()+(d));
//         reverse(arr.begin()+d,arr.end());
//         reverse(arr.begin(),arr.end());
//         for(int it:arr){
//             cout<<it<<" ";
//         }
//     return 0;
// }



// // Rotate array from right by d positions
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//         vector<int> arr = {1,4,6,2,7,3,9,4,};
//         int d = 4;

//         int n = arr.size();
//         vector<int> temp(n);
//         d = d%n;
//         for(int i=0;i<n;i++){
//             temp[(i+d)%n] = arr[i];
//         }
//         arr = temp;
//         for(int it:arr){
//             cout<<it<<" ";
//         }
//     return 0;
// }