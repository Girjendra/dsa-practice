#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> mpp1;
    mpp1[1] = 2;   
    mpp1.emplace(3, 1);
    mpp1.insert({2, 4});
    mpp1.insert({6, 4});
    mpp1.insert({8, 4});
    mpp1.insert({14, 4});
    
    for (auto it : mpp1) {
        cout << it.first << " " << it.second << endl;
    }
    
    map<int, pair<int, int>> mpp2;
    mpp2[4] = {3,5}; 
    cout << mpp2[4].first<<" "<<mpp2[4].second<<endl;
    
    map<pair<int, int>, int> mpp3;
    mpp3[{2, 3}] = 10;
    cout << mpp3[{2,3}]<<endl;
    
    // Finding an element in the map
    auto it1 = mpp1.find(3);
    cout << (*it1).first<<" "<< (*it1).second<<endl;
    
    // Attempting to find a non-existent key
    auto it2 = mpp1.find(5);
    // Check if the iterator is valid before dereferencing
    // This prevents dereferencing a null iterator which would cause undefined behavior
    if (it2 != mpp1.end()) {
        cout << (*it2).first<<" "<< (*it2).second<<endl;
    } else {
        cout << "Key not found" << endl;
    }

    // Demonstrating lower_bound and upper_bound
    auto lb = mpp1.lower_bound(2); // First element not less than 2

    if (lb != mpp1.end()) {
        cout << "Lower bound of 2: " << lb->first << " " << lb->second << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    
    auto ub = mpp1.upper_bound(3); // First element greater than 3

    if (ub != mpp1.end()) {
        cout << "Upper bound of 3: " << ub->first << " " << ub->second << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }
    
    return 0;
}