/*
You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.

Constraints:
1 <= n <= 105
*/
#include<iostream>
using namespace std;


// TC : O(1)
class Solution {
public:
    int countCommas(int n) {
        if(n < 1000)
            return 0;
        else
            return n - 999;
    }
};