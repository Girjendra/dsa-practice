#include<iostream>
#include<vector>
using namespace std;
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
int main(){
    vector<int> arr = {1,7,3,6,5,6};
    if(pivotIndex(arr))
    cout<<"Pivot index is: "<<pivotIndex(arr)<<endl;
    return 0;
}