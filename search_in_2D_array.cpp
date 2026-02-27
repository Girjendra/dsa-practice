#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();

    int rowind = 0;
    int colind = c - 1;

    while (rowind < r && colind >= 0) {
        int elem = matrix[rowind][colind];
        if (elem == target) {
            return true;
        }
        if (elem < target) {
            rowind++;
        } else {
            colind--;
        }
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "Target " << target << " found in the matrix." << endl;
    else
        cout << "Target " << target << " not found in the matrix." << endl;
    return 0;
}
