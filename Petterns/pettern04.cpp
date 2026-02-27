#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    int row =1;
    while (row<=n){
        int count1 = row-1;
        while (count1--)
        {
            cout<<" ";
        }
        int count = n-row+1;
        while (count--){
            cout<<"*";
        }
        row++;
        cout<<endl;
    }
    return 0;
}
/*
*******
 ******
  *****
   ****
    ***
     **
      *
*/