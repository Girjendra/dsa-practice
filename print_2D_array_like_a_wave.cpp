#include <bits/stdc++.h>
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> v;
    for(int i=0;i<mCols;i++){
        for(int j=0;j<nRows;j++){
            if(i%2==0){
                v.push_back(arr[j][i]);
            }
            else{
                v.push_back(arr[nRows-1-j][i]);
            }
        }
    }
    return v;
}
int main(){
    vector<vector<int>> arr ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int nRows = arr.size();
    int mCols = arr[0].size();
    vector<int> result = wavePrint(arr, nRows, mCols);

    cout << "Wave print of the 2D array is:\n";
    for (int x : result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
