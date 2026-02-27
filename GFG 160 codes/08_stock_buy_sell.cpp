#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
        int n = prices.size();
        int prof = 0;
        int minprice = prices[0];
        for(int i=1;i<n;i++){
                prof = max(prof,(prices[i]-minprice));
                minprice = min(minprice,prices[i]);
        }
        cout<<prof<<endl; 
    return 0;
}