/*
Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number - 
1. Get ith bit
2. Set ith bit
3. Clear ith bit
Note : For better understanding, we are starting bits from 1 instead 0. (1-based).
You have to print space three space separated values ( as shown in output without a line
break) and do not have to return anything.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int c = i-1;
        int bit = (1 & (num >> c));
        
        int temp1 = num;
        if(!bit) {
            temp1 += pow(2,i-1);
        }
        
        int temp2 = num;
        if(bit) {
            temp2 -= pow(2,i-1);
        }
        
        cout << bit << " " << temp1 << " " << temp2;
    }
};