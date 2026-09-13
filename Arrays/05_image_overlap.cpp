/*
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.
*/
#include<iostream>
#include <vector>
using namespace std;




// TC : O(n^4)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                        vector<vector<int>>& img2) {
        
        int n = img1.size();
        int ans = 0;

        for(int dx = -(n - 1); dx <= n - 1; dx++) {
            for(int dy = -(n - 1); dy <= n - 1; dy++) {

                int overlap = 0;
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {

                        if(img1[i][j] == 1) {

                            int x = i + dx;
                            int y = j + dy;

                            if(x >= 0 && x < n &&
                                y >= 0 && y < n &&
                                img2[x][y] == 1) {
                                
                                overlap++;
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};