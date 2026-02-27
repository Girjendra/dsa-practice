#include <bits/stdc++.h>
using namespace std;
void substring(const string& str,string& output,vector<string>& ans,int i){
	if(i == str.length()){
		if(output.length() > 0)
			ans.push_back(output);
		return ;
	}
	substring(str,output,ans,i+1);

	output.push_back(str[i]);
	substring(str,output,ans,i+1);
	output.pop_back();
}
void subsequences(const string& str,vector<string>& ans){
    string output = "";
	substring(str,output,ans,0);
}

int main(){
    string str = "abcde";
    vector<string> ans;
    subsequences(str,ans);

    for(auto str:ans){
        cout<<str<<"  ";
    }
    return 0;
}