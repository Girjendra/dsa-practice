#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    for(int it : b){
        a.push_back(it);
    }

    sort(a.begin(), a.end());
    int n1 = a.size();
    int m = b.size();
    for(int i = n, j = 0; i < n1; i++, j++){
        b[j] = a[i];
    }
    a.erase(a.begin() + n, a.end());
}
int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 4, 6, 8};
    mergeArrays(a, b);

    cout << "Array a after merge: ";
    for(int x : a)
        cout << x << " ";
    cout << endl;

    cout << "Array b after merge: ";
    for(int x : b)
        cout << x << " ";
    cout << endl;
    return 0;
}
