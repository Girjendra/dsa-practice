#include <bits/stdc++.h> 
using namespace std; 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
		vector<int>  c;

		int i = n-1;
		int j = m-1;
		int carry = 0;
		int sum = 0;
		while(i>=0&&j>=0){
			sum = a[i]+b[j]+carry;
			carry = sum/10;
			int degit = sum%10;
			c.push_back(degit);
			i--;
			j--;
		}

		while(i>=0){
			sum = a[i]+carry;
			carry = sum/10;
			int degit = sum%10;
			c.push_back(degit);
			i--;
		}		
		
		while(j>=0){
			int sum = b[j]+carry;
			carry = sum/10;
			int degit = sum%10;
			c.push_back(degit);
			j--;
		}

		while(carry!=0){
			int sum = carry;
			carry = sum/10;
			int degit = sum%10;
			c.push_back(degit);
		}

        reverse(c.begin(),c.end());
		return c;
}
int main(){
    vector<int> a = {2,3,3};
    vector<int> b = {2,3,3};
    vector<int> c = findArraySum(a,a.size(),b,b.size());
    for(int it:c)
        cout<<it<<" ";
    return 0;
}