// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;

//     int ans = 0,i = 0;
//     if(n==0)
//         return 1;

//     while(n){
//         int bit = (n&1);
//         bit = 1 - bit;      // bit = ~bit is wrong
//         ans = ans+bit*pow(2,i);
//         n = n>>1;
//         i++;
//     }

//     cout<<"One's complement is :"<<ans<<endl;
//     return 0;
// }



// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;

//     int m = n;
//     int mask = 0;

//     // edge case: if n is 0, its complement is 1
//     if (n == 0) 
//         return 1;

//     while (m) {
//         mask = (mask << 1) | 1;
//         m = m >> 1;
//     }

//     cout<<m<<endl;
//     int ans = (~n) & mask;
//     cout<<"One's complement is :"<<ans<<endl;
//     return 0;
// }