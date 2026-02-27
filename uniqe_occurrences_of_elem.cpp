/*
Given an array of integers arr, return true if the number of o
ccurrences of each value in the array is unique or false otherwise.
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    // vector<int> arr = {1,2,2,1,1,3};
    // vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    vector<int> arr = {1,2};
    int size = arr.size();

    set<int> s;
    set<int> s1;
    multiset<int> ms;
    for(int it:arr){
        s.insert(it);
        ms.insert(it);
    }
    int count1  = 0;
    bool ans = true;

    for(int it:s){
        count1 = ms.count(it);
        s1.insert(count1);
    }
    if(s.size()==s1.size())
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    return 0;
}