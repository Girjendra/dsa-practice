#include <bits/stdc++.h>
using namespace std;
// TC -> O(n)
// SC -> O(1)
long long int rob(vector<int>& valueInHouse) {
    int size = valueInHouse.size();

    if(size == 1)
        return valueInHouse[0];

    long long int prev1 = valueInHouse[0];
    long long int prev2 = 0;
    for(int i = 1; i < size-1; i++) {
        long long int inc = prev2 + valueInHouse[i%size];
        long long int exc = prev1 + 0;
        long long int cur = max(inc, exc);

        prev2 = prev1;
        prev1 = cur;
    }
    long long int ans1 = prev1;


    prev1 = valueInHouse[1];
    prev2 = 0;
    for(int i = 2; i < size; i++) {
        long long int inc = prev2 + valueInHouse[i%size];
        long long int exc = prev1 + 0;
        long long int cur = max(inc, exc);

        prev2 = prev1;
        prev1 = cur;
    }
    long long int ans2 = prev1;


    return max(ans1, ans2);
}

long long int houseRobber(vector<int>& valueInHouse){
    return rob(valueInHouse);
}