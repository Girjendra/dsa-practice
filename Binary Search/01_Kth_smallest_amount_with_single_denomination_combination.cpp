/*
You are given an integer array coins representing coins of different denominations and an integer k.

You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// TC : O(n * 2^n * log(max(coins) * k)), where n is the number of denominations in the coins array. The 2^n factor comes from generating all subsets of the coins array, and the log(max(coins) * k) factor comes from the binary search over the range of possible amounts.
class Solution {
public:
    long long gcd(long long a, long long b) {
        while(b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool ok = true;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);
                    if(L > x) {
                        ok = false;
                        break;
                    }
                }
            }

            if(!ok)
                continue;

            long long cnt = x / L;

            if(bits % 2)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while(low < high) {
            long long mid = low + (high - low) / 2;

            if(count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};