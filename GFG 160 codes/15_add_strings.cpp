#include<iostream>
#include<string>
using namespace std;
int main(){
        string s1 = "1101";
        string s2 = "111";
        // your code here
        int i = s1.size()-1;
        int j = s2.size()-1;
        int carry = 0;
        string res = "";
        while(i>=0||j>=0||carry){
            int sum = carry;
            if(i>=0)
                sum+=s1[i--]-'0';
            if(j>=0)
                sum+=s2[j--]-'0';
            res = char(sum%2+'0')+res;
            carry = sum/2;
        }
        while(res.size()>1&&res[0]=='0')
        res.erase(0,1);

        cout<<res<<endl;
    return 0;
}