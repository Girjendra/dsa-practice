/*
You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
*/
#include<iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int totalNumbers(vector<int>& dig) {
        int n = dig.size();
        
        int ans = 0;
        vector<int> check(1000, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k)
                        continue;
                        
                    int num = dig[i]*100 + dig[j]*10 + dig[k];
                    if((num % 2 == 0) && check[num] == 0 && num >= 100) {
                        ans++;
                        check[num] = 1;
                    }
                }
            }
        }

        return ans;
    }
};