#include<iostream>
using namespace std;
int main(){
    int amount;
    cout<<"Enter the amount to withdraw: ";
    cin>>amount;
    
    int n100 = 0,n50 = 0,n20 = 0,n1 = 0,am = amount;
    while (am){
        int x;
        if((am/100)>=1)
        x = 100;
        else if((am/50)>=1)
        x = 50;
        else if((am/20)>=1)
        x = 20;
        else if((am/1)>=1)
        x = 1;

        switch (x){
        case 100:
            n100=am/100;
            am=am%100;
            break;
        
        case 50:
            n50=am/50;
            am%=50;
            break;
        
        case 20:
            n20=am/20;
            am%=20;
            break;
        
        case 1:
            n1=am/1;
            am%=1;
            break;
        
        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    
    cout<<"No of 100 ruees notes: "<<n100<<endl;
    cout<<"No of 50 ruees notes: "<<n50<<endl;
    cout<<"No of 20 ruees notes: "<<n20<<endl;
    cout<<"No of 1 ruees notes: "<<n1<<endl;
    return 0;
}