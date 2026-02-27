/*
You are given an array ‘A’ of ‘N’ distinct integers numbered from ‘0’ to
‘N - 1’. You are also given another two integers ‘K’ and ‘X’. Your task is
to find the ‘kth’ smallest number among all those numbers which are not divisible
by ‘X’ in the array ‘A’.

Your task is to tell the ‘kth’ smallest number among all those numbers which are
not divisible by ‘X’ and return it. If it doesn't exist, return “-1”.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthInteger (int n, int k, int x, vector <int> &a) {
   if(k>a.size())
      return -1;

   for(int i=0;i<a.size();i++){
      if(a[i]%x == 0){
         a.erase(a.begin()+i);
         i--;
      }
   }

   if(a.empty() != 1 && k<=a.size()){
      sort(a.begin(),a.end());
      return a[k-1];
   }
   else
      return -1;
}
int main() {
    vector<int> a = {3, 6, 1, 8, 5, 10};
    int n = a.size();
    int k = 3;
    int x = 2;
    int result = kthInteger(n, k, x, a);
    cout << result << endl;
    return 0;
}