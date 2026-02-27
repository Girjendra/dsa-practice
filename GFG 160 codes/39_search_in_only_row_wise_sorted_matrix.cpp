#include <iostream>
#include <vector>
using namespace std;

// Function to search a given number in only row-wise sorted matrix.
bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        if(x>=mat[i][0] && x<=mat[i][m-1]){
            int s = 0;
            int e = m-1;
            int mid = s+(e-s)/2;
            while(s<=e){
                if(mat[i][mid]==x)
                    return true;
                if(mat[i][mid]>x)
                    e = mid-1;
                else
                    s = mid+1;
                mid = s+(e-s)/2;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int x = 5;
    if(searchRowMatrix(mat, x))
        cout << x << " found in matrix\n";
    else
        cout << x << " not found in matrix\n";
    return 0;
}