#include<iostream>
#include<string>
using namespace std;
bool areRotations(string &s1, string &s2) {
    string temp = s1+s1;
    return (temp.find(s2)!=string::npos);
}
int main(){
    string s1 = "girjendra";
    string s2 = "jendragir";
    if(areRotations(s1,s2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}