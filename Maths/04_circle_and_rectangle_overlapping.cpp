/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

Constraints:
1 <= radius <= 2000
-104 <= xCenter, yCenter <= 104
-104 <= x1 < x2 <= 104
-104 <= y1 < y2 <= 104
*/
#include<iostream>
using namespace std;



// TC : O(1)
class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xclo = max(x1, min(xc, x2));
        int yclo = max(y1, min(yc, y2));

        int dist = (xc - xclo)*(xc - xclo) + (yc - yclo)*(yc - yclo);

        return r*r >= dist;
    }
};