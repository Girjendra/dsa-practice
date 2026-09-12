/*
You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

Constraints:
1 <= intevals.length <= 5 * 104
intervals[i].length == 3
intervals[i] = [li, ri, weighti]
1 <= li <= ri <= 109
1 <= weighti <= 109
*/
#include<iostream>
#include <vector>
#include <climits>
#include <array>
#include <algorithm>
using namespace std;




class Solution {
public:
    struct State {
        long long score = 0;
        array<int, 4> ids = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int len = 0;
    };

    bool better(const State& a, const State& b) {
        if(a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store original index
        for(int i = 0; i < n; i++)
            intervals[i].push_back(i);

        // Sort by starting point
        sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            });

        vector<int> starts(n);

        for(int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        // next[i] = first interval whose start > intervals[i].end
        vector<int> next(n);

        for(int i = 0; i < n; i++) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                intervals[i][1]
            ) - starts.begin();
        }

        // dp[i][k] = best answer from i onward using at most k intervals
        vector<array<State, 5>> dp(n + 1);

        for(int i = n - 1; i >= 0; i--) {

            for(int k = 1; k <= 4; k++) {

                // Skip current interval
                State skip = dp[i + 1][k];

                // Take current interval
                State take = dp[next[i]][k - 1];

                take.score += intervals[i][2];

                // Add original index
                take.ids[take.len] = intervals[i][3];
                take.len++;

                // Sort only maximum 4 elements
                sort(take.ids.begin(),
                    take.ids.begin() + take.len);

                if(better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        vector<int> ans;

        for(int i = 0; i < dp[0][4].len; i++)
            ans.push_back(dp[0][4].ids[i]);

        return ans;
    }
};