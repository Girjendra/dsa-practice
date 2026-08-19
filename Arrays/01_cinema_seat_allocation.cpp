/*
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [row_i, seat_i] means that seat seat_i in row row_i is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.

Constraints:

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10 * n, 10^4)
reservedSeats[i] == [row_i, seat_i]
1 <= row_i <= n
1 <= seat_i <= 10
All reservedSeats[i] are distinct.


*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC : O(m) where m is the number of reserved seats
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int, vector<int>> m;
        for(auto it : rs) {
            m[it[0]].push_back(it[1]);
        }

        int ans = (n - m.size())*2;

        for(auto it : m) {
            vector<int> pos(11, 0);

            for(int seat : it.second)
                pos[seat] = 1;

            for(int i = 2; i <= 6; i += 2) {
                if(!pos[i] && !pos[i+1] && !pos[i+2] && !pos[i+3]) {
                    ans++;
                    pos[i] = pos[i+1] = pos[i+2] = pos[i+3] = 1;
                }
            }
        }

        return ans;
    }
};