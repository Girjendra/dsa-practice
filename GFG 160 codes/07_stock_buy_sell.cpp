#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    int n = prices.size();
        
    int a=0;
    int max = 0,prof = 0;
    for(int i=0;i<n-1;i++){
        if((prices[i+1]>prices[a])&&(prices[i+1]>prices[i]))
            max = (prices[i+1]-prices[a]);
        else{
            prof+=max;
            max = 0;
            a=i+1;
        }
    }
    prof+=max;
    cout<<"Max profit is: "<<prof<<endl;
    return 0;
}



// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//     vector<int> prices = {100,180, 260, 310, 40, 535, 695};
//     int n = prices.size();
//     int profit = 0;

//     for (int i = 1; i < n; i++) {
//         if (prices[i] > prices[i - 1]) {
//             profit += prices[i] - prices[i - 1];
//         }
//     }
//     cout << "Max profit is: " << profit << endl;
//     return 0;
// }