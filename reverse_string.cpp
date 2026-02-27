/*
You are given a string 'S'. Your task is to check
whether the string is palindrome or not. For
checking palindrome, consider alphabets and
numbers only and ignore the symbols and whitespaces.
Note : String 'S' is NOT case sensitive.
*/
// #include<iostream>
// #include<string>
// using namespace std;
// bool checkPalindrome(string s){
//     int n = s.size();
//     int k = 0;
//     for(int i=0;i<n;i++){
//         if(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'){
//             s[k] = s[i];
//             k++;
//         }
//     }
//     s.resize(k);
//     n = s.size();
//     string a = s;
//     for(int i=0;i<n/2;i++){
//         a[i]=toupper(a[i]);
//         a[n-i-1]=toupper(a[n-i-1]);
//         s[i]=toupper(s[i]);
//         s[n-i-1]=toupper(s[n-i-1]);
//         swap(a[i],a[n-i-1]);
//     }
//     if(a==s)
//         return true;
//     else
//         return false;
// }
// int main(){
//     string s = "c1 O$d@eeD o1c";
//     if(checkPalindrome(s))
//         cout<<"Palindrom"<<endl;
//     else
//         cout<<" Not palindrom"<<endl;
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s){
    string cleaned = "";
    
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

int main(){
    string s = "c1 O$d@eeD o1c";
    if(checkPalindrome(s))
        cout<<"Palindrom"<<endl;
    else
        cout<<" Not palindrom"<<endl;
    return 0;
}