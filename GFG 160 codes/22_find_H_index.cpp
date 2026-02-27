// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
//     bool ishindex(vector<int> citations, int h, int n) {
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             if(citations[i] >= h)
//                 count++;
//         }
//         return count >= h;
//     }
    
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(), citations.end());
//         int n = citations.size();
//         for(int h = n; h >= 0; h--) {
//             if(ishindex(citations, h, n))
//                 return h;
//         }
//         return 0;
//     }
    
// int main(){
//     // vector<int> arr = {5, 1, 2, 4, 1};
//     vector<int> arr = {8,12,10,12,9,12};
//     cout<<"H-index is: "<<hIndex(arr)<<endl;
//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n, ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count of papers with citations >= mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (citations[i] >= mid) {
                    count = n - i;
                    break;
                }
            }
            
            if (count >= mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }    
int main(){
    // vector<int> arr = {5, 1, 2, 4, 1};
    vector<int> arr = {8,12,10,12,9,12};
    cout<<"H-index is: "<<hIndex(arr)<<endl;
    return 0;
}