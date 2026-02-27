#include<iostream>
using namespace std;
int setbit(int a,int b){
    int count  = 0;
    int bit;
    while (a||b){
        bit = a&1;
        if(bit==1)
        count++;
        a>>=1;

        bit = b&1;
        if(bit==1)
        count++;
        b>>=1;
    }
    return count;
}
int main(){
    int a,b;
    cout<<"Enter a and b:"<<endl;
    cin>>a>>b;

    cout<<"Total no of bits(1's): "<<setbit(a,b)<<endl;
}