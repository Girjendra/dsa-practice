// #include <iostream>
// #include <vector>
// using namespace std;
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;

//         for(int i = 1; i < n; i++) {
//             if(nums[i - 1] > nums[i])
//                 count++;
//         }
//         if(nums[n - 1] > nums[0])
//             count++;

//         return count <= 1;
//     }
// int main() {
//     // vector<int> nums = {3, 4, 5, 1, 2};
//     vector<int> nums = {2,1,3,4};

//     if(check(nums))
//         cout << "Array is sorted and rotated." << endl;
//     else
//         cout << "Array is NOT sorted and rotated." << endl;

//     return 0;
// }



// #include <iostream>
// #include <vector>
// using namespace std;
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             if(nums[i] > nums[(i + 1) % n])
//                 count++;
//         }
//         return count <= 1;
//     }  
// int main() {
//     vector<int> nums = {3, 4, 5, 1, 2};
//     // vector<int> nums = {2,1,3,4};

//     if(check(nums))
//         cout << "Array is sorted and rotated." << endl;
//     else
//         cout << "Array is NOT sorted and rotated." << endl;

//     return 0;
// }





// will not pass all cases eg. {6,10,6}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    bool check(vector<int>& nums) {
        int n = nums.size();
        int min_index = distance(nums.begin(),min_element(nums.begin(),nums.end()));
        int x = min_index;

        vector<int> b = nums;
        vector<int> c(n);

        sort(b.begin(),b.end());

        for(int i=0;i<n;i++){
            c[i] = b[(i + n - x) % n];
        }
        if(c==nums)
            return true;
        else
            return false;
    }

int main() {
    // vector<int> nums = {3, 4, 5, 1, 2};
    // vector<int> nums = {2,1,3,4};
    vector<int> nums = {6,10,6};

    if(check(nums))
        cout << "Array is sorted and rotated." << endl;
    else
        cout << "Array is NOT sorted and rotated." << endl;

    return 0;
}
