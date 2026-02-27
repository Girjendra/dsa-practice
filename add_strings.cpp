using namespace std;
#include <bits/stdc++.h> 
string stringSum(string &num1, string &num2) {
    int sum = 0;
    int carry = 0;
    int i = num1.length()-1;
    int j = num2.length()-1;
    string s = "";
    
    while(i>=0 || j>=0 || carry != 0){
        int n1 = 0;
        int n2 = 0;
        sum = 0;
        
        if(i>=0){
            n1 = num1[i]-'0';
            i--;
        }
        
        if(j>=0){
            n2 = num2[j]-'0';
            j--;
        }            
        
        sum = n1+n2+carry;
        carry = sum/10;
        
        s.push_back(sum%10+'0');
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string num1 = "12345";
    string num2 =  "6789";
    string result = stringSum(num1, num2);
    cout << "Sum: " << result << endl;
    return 0;
}