/*
Given a positive integer n, determine whether it is odd or even.
Return true if the number is even and false if the number is odd.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isEven(int n) {
       return (1 & n) == 0;
    }
};