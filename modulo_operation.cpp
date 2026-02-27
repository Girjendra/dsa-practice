#include <bits/stdc++.h>
// (x^n)%m
int modularExponentiation(int x, int n, int m) {
    int res = 1;
    while(n>0){
        if(n&1){
            res = (1ll*(res)*(x)%m)%m;
        }
        x = (1ll*(x)%m*(x)%m)%m;
        n = n>>1;
    }
    return res;
}

int main() {
    int x, n, m;
    std::cout << "Enter base (x), exponent (n), and modulus (m): ";
    std::cin >> x >> n >> m;
    int result = modularExponentiation(x, n, m);
    std::cout << "Result: " << result << std::endl;
    return 0;
}