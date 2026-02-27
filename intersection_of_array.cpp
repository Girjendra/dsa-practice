// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// int main(){
//         // vector<int> nums1 = {1,2,2,1};
//         // vector<int> nums2 = {2,2};

//         vector<int> nums1 = {1,4,3,1};
//         vector<int> nums2 = {2,2};
//         vector<int> v;
//         set<int> s1,s2;

//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         for (int num : nums1) s1.insert(num);
//         for (int num : nums2) s2.insert(num);

//         for (int it : s1) {
//             if (s2.find(it) != s2.end()) {
//                 v.push_back(it);
//             }
//         }
//         if(v.empty()==0)
//         for(int it:v){
//             cout<<it<<" ";
//         }
//         else
//         cout<<"No common elements "<<endl;
//     return 0;
// }



// best and known as two pointer approach#include<iostream>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    // vector<int> nums1 = {1,4,3,1};
    // vector<int> nums2 = {2,2};

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());    
    set<int> v;

    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m) {
        if(nums1[i] == nums2[j]) {
            v.insert(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    if(v.empty()==0)
    for(int it:v){
        cout<<it<<" ";
    }
    else
        cout<<"No common elements "<<endl;
    return 0;
}