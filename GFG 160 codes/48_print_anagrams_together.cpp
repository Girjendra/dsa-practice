/*
Given an array of strings, return all groups of strings that are anagrams.
The strings in each group must be arranged in the order of their appearance
in the original array. Refer to the sample case for clarification.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<string>> anagrams(vector<string>& arr) {
    unordered_map<string,vector<string>> m;
    for(auto st:arr){
        string temp = st;
        sort(temp.begin(),temp.end());
        m[temp].push_back(st);
    }
    vector<vector<string>> v;
    for(auto pair:m){
        v.push_back(pair.second);
    }
    return v;
}

int main() {
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    vector<vector<string>> result = anagrams(arr);

    for(const auto& group : result) {
        for(const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
