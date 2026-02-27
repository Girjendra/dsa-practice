// User function template for C++
#include <iostream>
#include <vector>
using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int r = mat.size();
    int c = mat[0].size();

    int rowind = 0;
    int colind = c-1;

    while(rowind < r && colind >=0){
        int elem = mat[rowind][colind];
        if(x == elem){
            return true;
        }

        if(x < elem)
            colind--;
        else
            rowind++;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int x = 29;
    if(matSearch(mat, x))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}