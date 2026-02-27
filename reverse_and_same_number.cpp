#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;


    
    // To get reverse number
    double ans = 0;
    while (n){
        ans = ans*10+n%10;
        n/=10;
    }
    cout<<"reverse number: "<<ans<<endl;

    // To get same number
    cout<<"Enter a number: ";
    cin>>n;
    ans = 0;
    int i=0;
    while (n){
        int rem = n%10;
        ans = rem*pow(10,i)+ans;
        n = n/10;
        i++;
    }
    cout<<"same number: "<<ans<<endl;
    return 0;
}