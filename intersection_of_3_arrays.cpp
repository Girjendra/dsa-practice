// #include <bits\stdc++.h>
// using namespace std;
// vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c){
//     vector<int> v;
//     for(int i=0;i<a.size();i++){
//          if(find(b.begin(),b.end(),a[i]) != b.end() 
//             && find(c.begin(),c.end(),a[i]) != c.end()){
//                  if(find(v.begin(),v.end(),a[i]) == v.end())
//                      v.push_back(a[i]);
//          }
//     }
//     return v;
// }
// int main() {
//      vector<int> a = {1, 5, 10, 20, 40, 80};
//      vector<int> b = {6, 7, 20, 80, 100};
//      vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

//      vector<int> result = findCommonElements(a, b, c);

//      cout << "Common elements: ";
//      for(int x : result) {
//           cout << x << " ";
//      }
//      cout << endl;

//      return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    unordered_set<int> s1(arr1.begin(), arr1.end());
    unordered_set<int> s2(arr2.begin(), arr2.end());
    unordered_set<int> s3(arr3.begin(), arr3.end());

    map<int, int> m;
    for (int it : s1) {
        m[it]++;
    }
    for (int it : s2) {
        m[it]++;
    }
    for (int it : s3) {
        m[it]++;
    }

    vector<int> v;
    for (auto pair : m) {
        if (pair.second == 3) {
            v.push_back(pair.first);
        }
    }
    return v;
}

int main() {
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> result = commonElements(arr1, arr2, arr3);

    cout << "Common elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
