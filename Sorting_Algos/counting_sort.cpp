#include<bits/stdc++.h>
using namespace std;
void printarr(vector<int> arr) {
    for(int it : arr)
        cout << it << " ";
    cout << endl;
}
// TC = O(N)
// SC = O(N)
void counting_sort(vector<int>& arr, int k) {
    int n = arr.size();
    
    vector<int> count(k+1);
    for(int it : arr)
    count[it]++;
    
    for(int i = 1; i <= k; i++){
        count[i] += count[i-1];
    }
    
    vector<int> b(n);
    for(int i = n - 1; i >= 0; i--) {
        b[--count[arr[i]]] = arr[i];
    }
    
    for(int i = 0; i < n; i++)
        arr[i] = b[i]; 
}
int main(){
    vector<int> arr = {1,2,6,5,3,8,9,0,1,3,1,6,0,4,7,3,2,6,5,8};
    int k = *max_element(arr.begin(), arr.end());
    printarr(arr);
    counting_sort(arr, k);
    printarr(arr);
    return 0;
}