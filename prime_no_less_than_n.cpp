// Time complexity = O(N*log(logN)))
// #include <iostream>
// #include <vector>
// using namespace std;
// int countPrimes(int n) {
//     vector<bool> prime(n + 1, true);
//     prime[0] = false;
//     prime[1] = false;

//     int count = 0;
//     for (int i = 2; i < n; i++) {
//         if (prime[i]) {
//             count++;
//             for (int j = 2 * i; j < n; j += i) {
//                 prime[j] = false;
//             }
//         }
//     }
//     return count;
// }
// int main() {
//     int n = 50000;
//     cout << "Number of primes less than " << n << " is: " << countPrimes(n) << endl;
//     return 0;
// }



// // TLE not efficient
// #include <iostream>
// #include <vector>
// using namespace std;
//     bool isprime(int n){
//         for(int i=2;i<=n/2;i++){
//             if(n%i==0)
//                 return false;
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         int count = 0;
//         for(int i=2;i<n;i++){
//             if(isprime(i))
//                 count++;
//         }
//         return count;
//     }
// int main() {
//     int n = 50000;
//     cout << "Number of primes less than " << n << " is: " << countPrimes(n) << endl;
//     return 0;
// }





// More efficient for a big range[10^6,10^9]
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Step 1: Simple Sieve to get primes up to sqrt(R)
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}
// Step 2: Segmented Sieve to find primes in [L, R]
void segmentedSieve(int L, int R) {
    int limit = sqrt(R) + 1;
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    for (int prime : primes) {
        int start = max(prime * prime, ((L + prime - 1) / prime) * prime);
        for (int j = start; j <= R; j += prime)
            isPrime[j - L] = false;
    }

    if (L == 1) isPrime[0] = false;

    for (int i = 0; i <= R - L; i++) {
        if (isPrime[i])
            cout << (i + L) << " ";
    }
    cout << endl;
}

int main() {
    int L = 10000, R = 90000;
    cout << "Primes between " << L << " and " << R << " are:\n";
    segmentedSieve(L, R);
    return 0;
}
