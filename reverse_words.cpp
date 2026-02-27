#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void reversewords(string& s){
    int n = s.size();
    int i=0;
    while(i < n){
        int st = i;
        while (s[i] !=' '&&s[i] !='\0'){
            i++;
        }
        reverse(s.begin()+st,s.begin()+i);
        i++;
    }
}
int main(){
    string s = "My name is girjendra lodha and yours";
    reversewords(s);
    cout<<s<<endl;
    return 0;
}