// /*
// A celebrity is a person who is known to all but does not know anyone
// at a party. A party is being organized by some people. A square matrix
// mat[][] (n*n) is used to represent people at the party such that if an
// element of row i and column j is set to 1 it means ith person knows jth person.
// You need to return the index of the celebrity in the party, if the
// celebrity does not exist, return -1.
// */

// // O(n*n) O(n) acceptable
// #include<bits/stdc++.h>
// using namespace std;

// // To find the index of celebrity 
// int celebrity(vector<vector<int>>& arr) {
//     int n = arr.size();
//     vector<bool> v1(n, true); // ✅ Correct

//     for(int j=0;j<n;j++) {
//         for(int i=0;i<n;i++) {
//             if(arr[i][j] != 1) {
//                 v1[j] = false;
//                 break;
//             }
//         }
//     }
    
//     vector<bool> v2(n, true); // ✅ Correct
//     for(int i=0;i<n;i++) {
//         if(v1[i] == true) {
//             for(int j=0;j<n;j++) {
//                 if(i != j && arr[i][j] == 1) {
//                     v2[i] = false;
//                     break;
//                 }
//             }
//         }        
//     }

//     for(int i=0;i<n;i++) {
//         if(v1[i] == true && v2[i] == true) {
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     vector<vector<int>> arr = {
//     {1, 1, 0},
//     {0, 1, 0},
//     {0, 1, 1} };

//     // vector<vector<int>> arr = {
//     // {1, 1},
//     // {1, 1} };

//     int celebindex = celebrity(arr);

//     cout<<"Celebrity index: "<<celebindex<<endl;
//     return 0;
// }




// O(n) O(n) best
#include<bits/stdc++.h>
using namespace std;

// To find the index of celebrity 
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    stack<int> st;
    
    // Step1:Push all elements into stack
    for(int i=0;i<n;i++) {
        st.push(i);
    }
    
    // Step2:Get two elements and compare them
    while(st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if(mat[a][b] == 1) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }
    
    // Single element in stack is potential celebrity
    // verify it
    int ans = st.top();
    
    int zerocount = 0;
    int onecount = 0;
    
    for(int i=0;i<n;i++) {
        if(mat[i][ans] == 1) {
            onecount++;
        }
    }
    
    if(onecount != n)
        return -1;
        
    for(int i=0;i<n;i++) {
        if(mat[ans][i] == 0) {
            zerocount++;
        }
    }
    
    if(zerocount != n-1)
        return -1;
        
    return ans;
}


int main(){
    vector<vector<int>> arr = {
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 1} };

    // vector<vector<int>> arr = {
    // {1, 1},
    // {1, 1} };

    int celebindex = celebrity(arr);

    cout<<"Celebrity index: "<<celebindex<<endl;
    return 0;
}