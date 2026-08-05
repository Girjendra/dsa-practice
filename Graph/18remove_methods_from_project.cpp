/*
You are maintaining a project that has n methods numbered from 0 to n - 1.

You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.
*/
#include<iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void findallsus(int k, map<int, pair<vector<int>, vector<int>>>& m, vector<bool>& issus) {
        issus[k] = true;
        int size = m[k].second.size();
        for(int i = 0; i < size; i++)
            if(!issus[m[k].second[i]])
                findallsus(m[k].second[i], m, issus);
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        map<int, pair<vector<int>, vector<int>>> m;

        for(auto it : in) {
            int u = it[0];
            int v = it[1];

            m[v].first.push_back(u); // v is called by u
            m[u].second.push_back(v); // u called v
        }

        vector<bool> issus(n, false);

        findallsus(k, m, issus);     

        vector<int> arr;
        for(int i = 0; i < n; i++)
            arr.push_back(i);

        vector<int> unsus;
        for(int i = 0; i < n; i++) {
            if(issus[i]) {
                for(int it : m[i].first)
                    if(!issus[it])
                        return arr;
            }
            else
                unsus.push_back(i);
        }

        return unsus;
    }
};