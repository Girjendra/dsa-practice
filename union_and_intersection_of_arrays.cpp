#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
        vector<int> a = {85, 25, 1, 32, 54, 6};
        vector<int> b = {85, 2};
        // code here
        
        int n = a.size() + b.size();
        set<int> s1;
        for(int i=0,j=0;i<a.size()||j<b.size();){
            if(i<a.size()){
                s1.insert(a[i]);
                i++;
            }
            if(j<b.size()){
                s1.insert(b[j]);
                j++;
            }
        }
        cout<<"Number of elements in union is: "<<s1.size()<<endl;
        cout<<"Number of elements in intersection is: "<<n-s1.size()<<endl;
    return 0;
}