#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int x) {
    int r = mat.size();
    int c = mat[0].size();
    
    int s = 0;
    int e = r * c - 1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        int elem = mat[mid / c][mid % c];
        if (x == elem)
            return true;
        
        if (x < elem)
            e = mid - 1;
        else
            s = mid + 1;
        
        mid = s + (e - s) / 2;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int x = 3;

    if (searchMatrix(mat, x))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}