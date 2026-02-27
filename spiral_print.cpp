#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    int count = 0;
    int total  = r * c;

    int str = 0;
    int stc = 0;
    int enr = r - 1;
    int enc = c - 1;

    vector<int> v;

    while (count < total) {
        // Traverse top row
        for (int index = stc; index <= enc && count < total; index++) {
            v.push_back(matrix[str][index]);
            count++;
        }
        str++;

        // Traverse ending column
        for (int index = str; index <= enr && count < total; index++) {
            v.push_back(matrix[index][enc]);
            count++;
        }
        enc--;

        // Traverse ending row
        for (int index = enc; index >= stc && count < total; index--) {
            v.push_back(matrix[enr][index]);
            count++;
        }
        enr--;

        // Traverse dtarting column
        for (int index = enr; index >= str && count < total; index--) {
            v.push_back(matrix[index][stc]);
            count++;
        }
        stc++;
    }
    return v;
}
int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order of the matrix is:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
