/*
You are given an array 'nums' consisting of first N positive integers.
But from the N integers, one of the integers occurs twice in the array,and one of
the integers is missing. You need to determine the repeating and the missing integer.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> findRepeatingAndMissingNumbers(vector<int> nums){
    vector<int> v;
    sort(nums.begin(),nums.end());
    int numsum = nums[0];
    int repting = 0;
    
    for(int i=1;i<nums.size();i++){
        if(nums[i-1] == nums[i]){
            v.push_back(nums[i]);
            repting = nums[i];
        }
        numsum+=nums[i];
    }
    int actsum = ((nums.size())*(nums.size()+1))/2;
    int missing = actsum - numsum + repting;
    v.push_back(missing);
    
    return v;
}
int main() {
    vector<int> nums = {4, 3, 6, 2, 1, 1};
    vector<int> result = findRepeatingAndMissingNumbers(nums);
    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;
    return 0;
}