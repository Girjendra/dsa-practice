/*
Given two positive integer n and  k, check if the kth index bit of n is set or not.
 Note: A bit is called set if it is 1. 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int bit = 1 & (n >> k);
        return bit == 1;
    }
};