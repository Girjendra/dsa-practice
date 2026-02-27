#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "girjendra";
    stack<char> st;

    for(auto ch:str){
        st.push(ch);
    }

    string ans = "";
    while(!st.empty()){
        char ch = st.top();
        ans += ch;
        st.pop();
    }

    cout << "Your answer is: " << ans << endl;
    return 0;
}