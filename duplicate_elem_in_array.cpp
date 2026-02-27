// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     // vector<int> arr = {1, 2, 3, 4, 4};
//     vector<int> arr = {1, 2, 3, 4, 5,6,5};
//     int n = arr.size();
//     int orsum = 0;
//     int dsum = 0;
//     for(int i=0;i<n;i++){
//         if(i+1!=n)
//         orsum+=i+1;
//         dsum+=arr[i];
//     }
//     cout<<(dsum-orsum)<<endl;;
//     return 0;
// }



#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 3, 4, 4};
    // vector<int> arr = {1, 2, 3, 4, 5,6,5};
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans^arr[i];   
    }
    for(int i=1;i<n;i++){
        ans = ans^i;
    }
    cout<<ans<<endl;;
    return 0;
}