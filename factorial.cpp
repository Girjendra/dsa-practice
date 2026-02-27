#include <bits/stdc++.h>
using namespace std;
int main() {
        int n;
        cout<<"Enter the value of n: ";
        cin >> n;

        vector<int> result;
        result.push_back(1); // Initialize with 1 (i.e., 0! = 1)

        for (int i = 2; i <= n; i++) {
            int carry = 0;
            for (int j = 0; j < result.size(); j++) {
                int prod = result[j] * i + carry;
                result[j] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                result.push_back(carry % 10);
                carry /= 10;
            }
        }

        // Output result in reverse order
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
        cout << endl;
    return 0;
}
