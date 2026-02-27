#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    int row = 1;
    while (row<=n){
        int space = n-row;
        while (space){
            cout<<" ";
            space-=1;
        }

        int k = 1;
        int col = 1;
        while (col<=row){
            cout<<k;
            k+=1;
            col+=1;
        }

        int start = row-1;
        while (start){
            cout<<start;
            start-=1;
        }
        
        row+=1;
        cout<<endl;
    }
    return 0;
}

/*
     1
    121
   12321
  1234321
 123454321
12345654321

*/