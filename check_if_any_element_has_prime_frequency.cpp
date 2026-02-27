/*
You are given an integer array nums.
Return true if the frequency of any element of the array is prime, otherwise, return false.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isprime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool checkPrimeFrequency(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int it : nums) {
        m[it]++;
    }
    for (auto pair : m) {
        if (isprime(pair.second) && pair.second != 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    if (checkPrimeFrequency(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
