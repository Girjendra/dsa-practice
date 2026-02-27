// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// int main(){
//     vector<int> nums = {4,3,2,7,8,2,3,1};
//     vector<int> v;
//     set<int> s;
//     multiset<int> ms;

//     for(int it:nums){
//         s.insert(it);
//         ms.insert(it);
//     }  

//     for(int it:s){
//         if(ms.count(it)==2){
//             v.push_back(it);
//         }
//     }

//     for(int it:v){
//        cout<<it<<" ";
//     }
//     return 0;
// }


// best
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> v;

    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i])-1;
        if(nums[index]<0){
            v.push_back(abs(nums[i]));
        }
        else{
            nums[index] = -nums[index];
        }
    }
    for(int it:v){
       cout<<it<<" ";
    }
    return 0;
}