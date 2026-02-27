#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
        string s1 = "girjendra";
        string s2 = "jengirdra";
        // Your code here
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2)
            cout<<"Strings are anagram"<<endl;
        else
            cout<<"Strings are not anagram"<<endl;
    return 0;
}