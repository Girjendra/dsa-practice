#include<iostream>
#include<vector>
using namespace std;
bool ispossible(vector<int> time,int n,int m,int mid){
	int studcount = 1;
	int pagecount = 0;

	for(int i=0;i<n;i++){
		if(pagecount+time[i]<=mid){
			pagecount+=time[i];
		}
		else{
			studcount++;
			if(studcount>m||time[i]>mid){
				return false;
			}
			pagecount = time[i];
		}
	}
	return true;
}
long long bookalocation(vector<int> arr,int n, int m) {	
	int sum =0;
	for(int it:arr) {
		sum+=it;
	}

	int st = 0;
	int end = sum;
	long long ans = -1;
	int mid = st + (end-st)/2;

	while(st<=end){
		if(ispossible(arr,n,m,mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			st = mid+1;
		}
		mid = st + (end-st)/2;
	}
	return ans;
}
int main(){
    vector<int> arr = {2,2,3,3,4,4,1};
    int books = 7;
    int stud = 4;
    cout<<"Ans is: "<<bookalocation(arr,books,stud)<<endl;
    return 0;
}