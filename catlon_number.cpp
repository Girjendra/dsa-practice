// // For upto 10th catlon number
// #include <iostream>
// using namespace std;
// // Function to compute factorial
// long long factorial(int n) {
//     long long res = 1;
//     for(int i = 2; i <= n; ++i)
//         res *= i;
//     return res;
// }

// // Function to compute nth Catalan number using formula
// long long catalan(int n) {
//     long long num = factorial(2 * n);
//     long long denom = factorial(n + 1) * factorial(n);
//     return num / denom;
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     cout << "Catalan numbers from 0 to " << n << " are:\n";
//     for(int i = 0; i <= n; ++i) {
//         cout << "C[" << i << "] = " << catalan(i) << endl;
//     }

//     return 0;
// }





// for large numbers using Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

long long catalanDP(int n) {
    vector<long long> catalan(n+1, 0);
    catalan[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }

    return catalan[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Catalan Number C_" << n << " = " << catalanDP(n) << endl;
    return 0;
}





// Efficient with DP and Modular Arithmetic
// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1e9 + 7;
// const int MAX = 1e5; // adjust according to needs

// vector<long long> fact(MAX), invFact(MAX);

// // Fast exponentiation: a^b % MOD
// long long power(long long a, long long b) {
//     long long res = 1;
//     while(b > 0) {
//         if(b & 1)
//             res = (res * a) % MOD;
//         a = (a * a) % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// // Precompute factorials and inverse factorials
// void precompute() {
//     fact[0] = invFact[0] = 1;
//     for(int i = 1; i < MAX; ++i) {
//         fact[i] = (fact[i-1] * i) % MOD;
//         invFact[i] = power(fact[i], MOD - 2); // Fermat's Little Theorem
//     }
// }

// // Compute nth Catalan number modulo MOD
// long long catalan(int n) {
//     long long res = fact[2*n];
//     res = (res * invFact[n]) % MOD;
//     res = (res * invFact[n+1]) % MOD;
//     return res;
// }

// int main() {
//     precompute();
    
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     cout << "Catalan number C[" << n << "] = " << catalan(n) << endl;

//     return 0;
// }
