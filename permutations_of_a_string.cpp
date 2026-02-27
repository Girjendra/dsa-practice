#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void permutation(vector<int>& nums, vector<vector<int>>& ans, int index) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        permutation(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    permutation(nums, ans, 0);

    for (const auto& perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}