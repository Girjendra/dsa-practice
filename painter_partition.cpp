#include<iostream>
#include<vector>
using namespace std;
bool ispossible(vector<int> &boards,int n,int k,int mid){
    int lengthcount = 0;
    int paintercount = 1;
    for(int i=0;i<n;i++){
        if(lengthcount+boards[i]<=mid){
            lengthcount+=boards[i];
        }
        else{
            paintercount++;
            if(paintercount>k||boards[i]>mid){
                return false;
            }
            lengthcount = boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards,int n, int k)
{
    int sum  = 0;
    for(int it:boards){
        sum+=it;
    }

    int st = 0;
    int end = sum;
    int mid = st+(end-st)/2;
    int ans = 0;
    while(st<=end){
        if(ispossible(boards,n,k,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
        mid = st+(end-st)/2;
    }
    return ans;
}
int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int lengts = 6;
    int painter = 2;
    cout<<"Ans is: "<<findLargestMinDistance(arr,lengts,painter)<<endl;
    return 0;
}