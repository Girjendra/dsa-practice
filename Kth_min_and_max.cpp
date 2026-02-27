#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {5,1,6,7,2,4,3,8,9};
    vector<int> v1 = arr;
    int  k = 4;

	for(int i=1;i<k;i++){
        *min_element(arr.begin(),arr.end()) = INT_MAX;
    }
    int min = *min_element(arr.begin(),arr.end());

	for(int i=1;i<k;i++){
        *max_element(v1.begin(),v1.end()) = INT_MIN;
    }
    int max = *max_element(v1.begin(),v1.end());

    cout<<k<<"th minimum element is: "<<min<<"\n"<<k<<"th maximum element is: "<<max<<endl;
    return 0;
}