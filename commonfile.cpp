#include<bits/stdc++.h>
using namespace std;
long reverseBits(long n) {
    string s = "";
    int limit = 32;
    while(limit--){
        int bit = n & 1;
        s.push_back(bit + '0');
        n = n>>1;
    }
    
    cout<<s<<endl;

    long num = 0;
    int j=0;
    for(int i=s.length()-1;i>=0;i--){
        int digit = s[i]-'0';
        num = num + digit * pow(2, j);
        j++;
    }
    return num;
}
int main() {
//    cout<<reverseBits(0l)<<endl;

    int ms = 1e9;
    cout<<ms<<endl;
    return 0;
}