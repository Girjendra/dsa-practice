// #include<iostream>
// #include<vector>
// using namespace std;
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> v;
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     v = {i,j};
//                 }
//             }
//         }
//     return v;
//     }
// int main(){
//     vector<int> arr = {2,4,7,8,};
//     int target = 9;
//     vector<int> v = twoSum(arr,target);
//     for(int it:v)
//         cout<<it<<" ";
//     return 0;
// }




#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
int main(){
    vector<int> arr = {2,4,7,8,};
    int target = 9;
    vector<int> v = twoSum(arr,target);
    for(int it:v)
        cout<<it<<" ";
    return 0;
}