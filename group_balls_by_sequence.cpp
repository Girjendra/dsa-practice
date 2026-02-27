#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool validgroup(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (i % k == 0)
            v.push_back(arr[i]);
    }

    
    sum = 2 * sum;
    int sum2 = 0;
    
    for (int i = 0; i < v.size(); i++) {
        sum2 += k * (2 * v[i] + k - 1);
    }
    
    cout<<"boss = "<<sum<<endl;
    cout<<"boss = "<<sum2<<endl;

    if (n % k == 0 && sum == sum2)
        return true;
    else
        return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;
    if (validgroup(arr, k))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
