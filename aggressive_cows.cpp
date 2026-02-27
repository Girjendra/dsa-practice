#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> &stalls, int k,int mid){
    int cowcount = 1;
    int lastpos = stalls[0];

    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();

    int s = 0;
    int e =stalls[n-1];

    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(ispossible(stalls,k,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> stalls = {0,3,4,7,10,9};
    int agg_cow = 4;
    cout<<"Ans is: "<<aggressiveCows(stalls,agg_cow)<<endl;
    return 0;
}