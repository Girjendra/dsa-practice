#include<iostream>
using namespace std;
long long int binarysearch(int n){
    int start = 0;
    int end = n;
    long long int mid = start + (end - start)/2;
    long long int ans = -1;
    while(start<=end){
        long long int square  = mid*mid;
        if(square==n){
            return mid;
        }
        if(square<n){
            start = mid +1;
            ans = mid;
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

double moreprecesion(int n,int precesion,int tempsolu){
    double factor = 1;
    double ans = tempsolu;
    for (int i = 0; i < precesion; i++){
        factor/=10;
        for (double j = ans;j*j < n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int tempsquare = binarysearch(n);
    cout<<"Square root of "<<n<<" to nearest lower integer is: "<<tempsquare<<endl;
    cout<<"Square root of "<<n<<" is: "<<moreprecesion(n,4,tempsquare)<<endl;

    return 0;
}