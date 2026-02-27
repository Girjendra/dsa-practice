/*
Ninja is given an integer ‘N’. Ninja wants to find whether
the binary representation of integer ‘N’ is palindrome or not.
A palindrome is a sequence of characters that reads the same backward as forward.
Ninja is busy with his training. Help Ninja in finding out
whether the binary representation of ‘N’ is palindrome or not.
*/

#include <bits/stdc++.h>
using namespace std;
string D2B(long long deci){
    string res = "";
    while (deci) {
        res += (deci & 1) ? '1' : '0';
        deci = deci >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool checkpalindrom(string s,int i,int j){
    if(i>j)
    return true;
    
    if(s[i]!=s[j])
    return false;
    else
    return checkpalindrom(s,i+1,j-1);  
}
bool checkPalindrome(long long N)
{
    string s = D2B(N);    
    return checkpalindrom(s,0,s.length()-1);
}
int main() {
    long long N = 9; // Hardcoded value, you can change it to test other numbers
    if(checkPalindrome(N)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}