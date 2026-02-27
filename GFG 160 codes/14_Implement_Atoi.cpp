#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
int main(){
    string s = "-99909f99";

    long long  n = 0;
    int i=0;
    bool sing  = false;
        
    while(s[i]==' '){
        i++;
    }
        
    if(s[i]=='-'||s[i]=='+'){
        if(s[i]=='-'){
            sing = true;
            i++;
         }
         else
           i++;
    }        
        
    while(s[i]>='0'&&s[i]<='9'){
        if(n>INT_MAX||(n==INT_MAX/10&&s[i]-'0'>7))
            if(!sing){
                cout<<INT_MAX<<endl;
                sing = 0;
                break;
            }
            else{
                cout<<INT_MIN<<endl;
                sing = 0;
                break;
            }
            n = n*10 + (s[i]-'0');
            i++;
    }      
    if(sing){
    n=-n;
    cout<<n<<endl;
    }
    return 0;
}