/*
You are given three integers 'A', 'B', and 'C'.
You are required to perform the following operation exactly '5' times:
• Either increment 'A' by 'B' or increment 'B' by 'C'.
Your task is to return the maximum possible value of 'A' after performing all the '5' operations.
*/

#include <iostream>
using namespace std;
int findMaximum(int a, int b, int c) {
    if (c >= b) {
        int temp = 4;
        while (temp--) {
            b += c;
        }
        a += b;
        return a;
    } else {
        int temp = 5;
        while (temp--) {
            a += b;
        }
        return a;
    }
}
int main() {
    int a = 2, b = 3, c = 4;   // 21
    // int a = 0, b = 0, c = 0;   // 0
    // int a = 2, b = 1, c = 0;   // 7
    // int a = 0, b = 10, c = 1;  // 50
    // int a = 1, b = 1, c = 2;   // 9
    int result = findMaximum(a, b, c);
    cout << "Maximum possible value of A: " << result <<endl;
    return 0;
}