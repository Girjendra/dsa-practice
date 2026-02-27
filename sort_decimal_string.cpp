// In descending order
// #include<iostream>
// #include<string>
// using namespace std;
// string sorted_num(string &n){
//     int freq[10] = {0};
//     for (char Ch : n) {
//         freq[Ch-'0']++;
//     }
//     int pos = 0;
//     for (int i = 9; i >= 0; i--) {
//         while (freq[i]--) {
//             n[pos++] = i+'0';
//         }
//     }
//     return n;
// }
// int main() {
//     string num = "3901284756";
//     cout << "Sorted in descending order: " << sorted_num(num) << endl;
//     return 0;
// }


// In ascending order
// #include<iostream>
// #include<string>
// using namespace std;
// string sorted_num(string &n){
//     int freq[10] = {0};
//     for (char Ch : n) {
//         freq[Ch-'0']++;
//     }
//     int pos = 0;
//     for (int i = 0; i <= 9; i++) {
//         while (freq[i]--) {
//             n[pos++] = i+'0';
//         }
//     }
//     return n;
// }
// int main() {
//     string num = "3901254566684756";
//     cout << "Sorted in ascending order: " << sorted_num(num) << endl;
//     return 0;
// }