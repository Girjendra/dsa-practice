#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    int row = 1;
    while (row<=n){
        int count1 = 1;
        while (count1<=(n-row+1)){
            cout<<count1;
            count1+=1;
        }

        int col1  = 1;
        while (col1<row){
            cout<<"*";
            col1+=1;
        }

        int col3 = 1;
        while (col3<row){
            cout<<"*";
            col3+=1;
        }
        
        int count2 = n-row+1;
        while (count2>=1){
            cout<<count2;
            count2-=1;
        }
        row+=1;
        cout<<endl;
    }
    return 0;
}

/*
1224554321
1234**4321
123****321
12******21
1********1
*/