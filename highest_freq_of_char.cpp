// #include<iostream>
// #include<string>
// #include<map>
// #include<climits>
// using namespace std;
//     char getMaxOccuringChar(string& s) {
//         map<char,int> m;
//         for(char ch:s){
//             m[ch]++;
//         }
        
//         int max = INT_MIN;
//         for(const auto& pair:m){
//             if(pair.second>max){
//                 max = pair.second;
//             }
//         }
        
//         char ch;
//         for(const auto& pair:m){
//             if(pair.second>=max){
//                 max = pair.second;
//                 ch = pair.first;
//                 break;
//             }
//         }
//         return ch;
//     }
// int main(){
//     string s = "ksfjhdjs";
//     cout<<"Highest frequency char: "<<getMaxOccuringChar(s)<<endl;
//     return 0;
// }




#include <iostream>
#include <string>
using namespace std;
char getMaxOccurringChar(string s) {
    int arr[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        }
        else {
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = -1, ans = 0;
    for(int i = 0; i < 26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}
int main() {
    string s = "GirjendraLodha";    // Not case sensitive
    cout << "Most frequent character: " << getMaxOccurringChar(s) << endl;
    return 0;
}
