#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>  arr = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < arr.size(); i+=2)
    {
        if(i+1<arr.size())
        swap(arr[i],arr[i+1]);
    }
    for(int it:arr){ 
        cout<<it<<" ";
    }
    return 0;
}