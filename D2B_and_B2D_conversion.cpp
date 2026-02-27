#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
double D2B(int deci){
    double num1 = 0;
    int i=0;
    while (deci){
        int bit = deci&1;
        num1 = bit*pow(10,i)+num1;
        deci = deci>>1;
        i++;
    }
    return num1;
}

double B2D(int bin){
    double num = 0;
    int i=0;
    while (bin){
        int digit = bin % 10;
        if(digit==1)
        num = num + pow(2,i);
        bin= bin/10;
        i++;
    }
    return num;
}

int main(){
    int choice;
    do{
        cout<<"1. Decimal to binary\n2. Binary to decimal\n3. To exit program"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        case 1:
        {
        int deci;
        cout<<"Entter decimal number: ";
            cin>>deci;
            cout<<"Decimal number "<<deci<<" in binary is: "<<D2B(deci)<<endl<<endl;
            break;

        case 2:
            int bin;
            cout<<"Entter binary number: ";
            cin>>bin;
            cout<<"Binary number "<<bin<<" in decimal is: "<<B2D(bin)<<endl<<endl;
            break;

            default :
            cout<<"Enter a valid choice"<<endl<<endl;
            break;
        }
    } while (choice!=3);
    
    return 0;
}


/*
Decimal to binary in the form of string

string D2B(long long deci){
    string res = "";
    while (deci) {
        res += (deci & 1) ? '1' : '0';
        deci = deci >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
*/