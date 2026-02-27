/*
You are given a rectangular matrix mat[][] of size n x m, and your
task is to return an array while traversing the matrix in spiral form.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > &mat) {
    int r = mat.size();
    int c = mat[0].size();
    
    int sr = 0;
    int sc = 0;
    int er = r-1;
    int ec = c-1;
    int elem = 0;
    
    vector<int> v;
    
    while(elem<r*c){
        for(int index = sc;index<=ec && elem<r*c;index++){
            v.push_back(mat[sr][index]);
            elem++;
        }
        sr++;
        
        for(int index = sr;index<=er && elem<r*c;index++){
            v.push_back(mat[index][ec]);
            elem++;
        }
        ec--;
        
        for(int index = ec;index>=sc && elem<r*c;index--){
            v.push_back(mat[er][index]);
            elem++;
        }
        er--;
        
        for(int index = er;index>=sr && elem<r*c;index--){
            v.push_back(mat[index][sc]);
            elem++;
        }
        sc++;
    }
    return v;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<int> result = spirallyTraverse(mat);
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}