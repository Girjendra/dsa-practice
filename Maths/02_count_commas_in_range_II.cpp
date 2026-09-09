/*
You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.

Constraints:
1 <= n <= 1015
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;



// TC : O(log10(n))
class Solution {
public:
    long long countCommas(long long n) {
        int d = 0;
        long long temp1 = n;
        while(temp1) {
            d++;
            temp1 /= 10;
        }

        long long ans = 0;
        vector<int> comma = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
        while(d) {
            long long temp2 = (long long)pow(10, d-1);

            ans += (n - temp2 + 1)*comma[d];
            n = temp2 - 1;
            d--;
        } 

        return ans;
    }
};