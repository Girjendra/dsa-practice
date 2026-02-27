// Rotate array from left by d positions
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        vector<int> arr = {1,4,6,2,7,3,9,4,};
        int d = 4;

        int n = arr.size();
        d = d%n;
        reverse(arr.begin(),arr.begin()+(d));
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
        for(int it:arr){
            cout<<it<<" ";
        }
    return 0;
}