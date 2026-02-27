// #include<iostream>
// #include<string>
// #include<set>
// using namespace std;
// int main(){
//     string s = "geeksforgeeks";
//         multiset<char> ms;
//         for(char ch:s){
//             ms.insert(ch);
//         }
//         for(char ch:ms){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
    
//         char Ch = '$';
//         for(char ch:s){
//             if(ms.count(ch)==1){
//                 Ch = ch;
//                 break;
//             }
//         }
//         cout<<Ch<<endl;
// }


// More efficient
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string s = "geeksforgeeks";
        unordered_map<char,int> ms;
        for(char ch:s){
            ms[ch]++;
        }
        char Ch = '$';
        for(char ch:s){
            if(ms[ch]==1){
                Ch = ch;
                break;
            }
        }
        cout<<Ch<<endl;
}