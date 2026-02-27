#include <bits/stdc++.h> 
using namespace std;
void printarray(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> topKFreq(vector<int> &arr, int k) {
    unordered_map<int,int> mp;
    int size = arr.size();
    vector<int> res;
    
    for(int i = 0; i < size; i++)
        mp[arr[i]]++;
    
    vector<pair<int,int>> vec;
    for(pair<int,int> it : mp)
        vec.push_back({it.second, it.first});
    
    int vecsize = vec.size();
    int maxind;
    
    for(int i = 0; i < k; i++) {
        
        int maxf = INT_MIN;
        maxind = -1;
        
        for(int j = 0; j < vecsize; j++) {
            if(maxf < vec[j].first) {
                maxf = vec[j].first;
                maxind = j;
            }
            else if(maxf == vec[j].first) {
                if(vec[maxind].second < vec[j].second)
                    maxind = j;
            }
        }
        
        res.push_back(vec[maxind].second);
        vec[maxind].first = INT_MIN;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8 , k = 2;
    

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> res = topKFreq(arr, k);
    printarray(res);
    return 0;
}