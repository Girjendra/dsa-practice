/*
An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.
*/
#include<iostream>
#include <vector>
using namespace std;



// TC : O(1)
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int width = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int height = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);

        return width > 0 && height > 0;
    }
};