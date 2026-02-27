#include<iostream>
using namespace std;
int fibbo(int n){
    cout<<"The fibbonacchi series is: ";
    int value,a = 0,b = 1;
    if(n==1){
        cout<<a<<endl;;
        return 0;
    }
    else if(n==2){
        cout<<a<<" ";
        cout<<b<<endl;;
        return 1;
    }

    cout<<a<<" ";
    cout<<b<<" ";
    for (int i = 0; i < n-2; i++){
    int c = a+b;
    a = b;
    b = c;
    value = c;
    cout<<c<<" ";
    }
    cout<<endl;
    return value;
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"The value of "<<n<<"th term is: "<<fibbo(n)<<endl;
}