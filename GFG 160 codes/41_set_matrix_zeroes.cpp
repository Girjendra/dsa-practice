/*
You are given a 2D matrix mat[][] of size n×m. The task is to modify
the matrix such that if mat[i][j] is 0, all the elements in the i-th row
and j-th column are set to 0 and do it in constant space complexity.v
*/
#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>> v;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == 0){
                v.push_back({i,j});
            }
        }
    }

    int n = v.size();
    for(int i=0;i<n;i++){
        int j=0;
        while(j<c){
            mat[v[i][0]][j] = 0;
            j++;
        }
    }

    for(int i=0;i<n;i++){
        int j=0;
        while(j<r){
            mat[j][v[i][1]] = 0;
            j++;
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {8, 2, 3},
        {0, 0, 6},
        {7, 8, 9}
    };

    setMatrixZeroes(mat);

    for(const auto& row : mat) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
