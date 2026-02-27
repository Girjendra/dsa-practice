// Find factorial 
// #include<iostream>
// using namespace std;
// int factorial(int n){
//     if(n==0)
//         return 1;
//     else
//         return n*factorial(n-1);
// }
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;
//     cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
//     return 0;
// }




// Find power of 2
// #include<iostream>
// using namespace std;
// int power(int n){
//     if(n==0)
//         return 1;
//     else
//         return 2*power(n-1);
// }
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;
//     cout<<"Value of 2 raise to power "<<n<<" is: "<<power(n)<<endl;
//     return 0;
// }


// Print counting
// #include<iostream>
// using namespace std;
// void print(int n){
//     if(n==0)
//         return ;

//     // cout<<n<<" ";
//     // print(n-1);

//     print(n-1);
//     cout<<n<<" ";
// }
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;
//     cout<<"Counting: "<<endl;
//     print(n);
//     return 0;
// }


/*
The Fibonacci numbers, commonly denoted F(n) form a sequence,
called the Fibonacci sequence, such that each number is the
sum of the two preceding ones, starting from 0 and 1.
*/
// #include<iostream>
// using namespace std;
// int fib(int n) {
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 1;
//     return fib(n-1) + fib(n-2);
// }
// int main() {
//     int n = 5; // hard coded value
//     cout << "Fibonacci of " << n << " is: " << fib(n) << endl;
//     return 0;
// }



// #include<iostream>
// using namespace std;
// int fib(int n) {
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 1;

//     int a = 0;
//     int b = 1;
//     int c;
//     for(int i=0; i<=n-2; i++) {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return c;
// }
// int main() {
//     int n = 5; // hard coded value
//     cout << "Fibonacci of " << n << " is: " << fib(n) << endl;
//     return 0;
// }


/*
input: int n = 421
output: four two one
*/
// #include<iostream>
// #include<string>
// using namespace std;
// void printdigits(int n,string arr[]){
//     if(n==0)
//         return ;

//     int digit = n%10;
//     n = n/10;
//     printdigits(n,arr);
//     cout<<arr[digit]<<" ";
// }
// int main(){
//     int n = 423451;
//     string arr[] = {
//         "zero", "one", "two", "three",
//         "four", "five", "six",
//         "seven", "eight", "nine"
//     };
//     printdigits(n,arr);
//     return 0;
// }



// Check wether a array is sorted or not
// #include<iostream>
// using namespace std;
// bool issorted(int arr[],int s){
//     if(s==0||s==1)
//         return true;
//     if(arr[0]>arr[1])
//         return false;
    
//     return issorted(arr+1,s-1);
// }
// int main(){
//     int arr[] = {1,2,3,5,5,5,5};
//     int s = 7;
//     if(issorted(arr,s))
//         cout<<"Array is sorted"<<endl;
//     else
//         cout<<"Array is not sorted"<<endl;
//     return 0; 
// }




// Find array sum
// #include<iostream>
// #include<vector>
// using namespace std;
// int arraysum(int arr[],int n){
//     if(n==0)
//         return 0;
//     return arr[0]+arraysum(arr+1,n-1);
// }
// int main(){
//     // int arr[] = {1,2,3,4,5};
//     int arr[] = {1,1,1,1,1};
//     int n = 5;
//     cout<<"Array sum is "<<arraysum(arr,n)<<endl;
//     return 0;
// }



// Linear search through recursion
// #include<iostream>
// using namespace std;
// bool search(int arr[],int n,int target){
//     if(n==0)
//         return false;
    
//     if(arr[0]==target)
//         return true;
    
//     return search(arr+1,n-1,target);
// }
// int main(){
//     int arr[] = {1,4,2,5,7,8,4,2};
//     int n = 8;
//     int target = 8;
//     if(search(arr,n,target))
//         cout<<"Element is found"<<endl;
//     else
//         cout<<"Element in not found"<<endl;
//     return 0;
// }





// // Binary search through recursion
// #include<iostream>
// #include<algorithm>
// using namespace std;
// bool search(int arr[],int s,int e,int target){
//     if(s>e)
//         return false;
    
//     int mid = s+(e-s)/2;
//     if(arr[mid]==target){
//         return true;
//     }

//     if(arr[mid]>target){
//         e = mid-1;
//     }
//     else{
//         s = mid+1;
//     }

//     return search(arr,s,e,target);
// }
// int main(){
//     int arr[] = {1,3,4,2,2,7,8,5};
//     int n = 8;
//     int target = 6;

//     int s = 0;
//     int e = n-1;
//     sort(arr,arr+n);

//     if(search(arr,s,e,target))
//         cout<<"Element is found"<<endl;
//     else
//         cout<<"Element is not found"<<endl;
//     return 0;
// }



// Reverse a given string
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// void Reverse(string& s,int n,int count){
//     if(count>=n/2)
//         return ;
//     if(count<n/2){
//         swap(s[count],s[n-1-count]);
//     }
//     Reverse(s,n,count+1);
// }
// int main(){
//     // string s = "abcd";
//     string s = "girjendra";
//     int n = s.length();
//     cout<<"String before reverse: "<<s<<endl;
//     Reverse(s,n,0);
//     cout<<"String after reverse: "<<s<<endl;
//     return 0;
// }







/*
Ninja is given an integer ‘N’. Ninja wants to find whether
the binary representation of integer ‘N’ is palindrome or not.
A palindrome is a sequence of characters that reads the same backward as forward.
Ninja is busy with his training. Help Ninja in finding out
whether the binary representation of ‘N’ is palindrome or not.
*/

// #include <bits/stdc++.h>
// using namespace std;
// string D2B(long long deci){
//     string res = "";
//     while (deci) {
//         res += (deci & 1) ? '1' : '0';
//         deci = deci >> 1;
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }

// bool checkpalindrom(string s,int i,int j){
//     if(i>j)
//     return true;
    
//     if(s[i]!=s[j])
//     return false;
//     else
//     return checkpalindrom(s,i+1,j-1);  
// }
// bool checkPalindrome(long long N)
// {
//     string s = D2B(N);    
//     return checkpalindrom(s,0,s.length()-1);
// }
// int main() {
//     long long N = 9; // Hardcoded value, you can change it to test other numbers
//     if(checkPalindrome(N)) {
//         cout << "Palindrome" << endl;
//     } else {
//         cout << "Not Palindrome" << endl;
//     }
//     return 0;
// }




// Finding b raise to power a optimally
// #include<iostream>
// using namespace std;
// int power(int a,int b){
//     if(b == 0)
//         return 1;
//     if(b == 1)
//         return a;
    
//     if(b%2==0)
//         return power(a,b/2)*power(a,b/2);
//     else
//         return a*power(a,b/2)*power(a,b/2);
// }
// int main(){
//     int a,b;
//     cout<<"Enter the value of a and b: "<<endl;
//     cin>>a>>b;
//     cout<<a<<" raise to power"<< b <<" is: "<<power(a,b);
//     return 0;
// }  




// Bubble sort
// #include<iostream>
// #include<vector>
// using namespace std;
// void bubblesort(vector<int>& v,int n){
//     if(n==1)
//         return ;

//     int maxindex;
//     for(int i=1;i<n;i++){
//         if(v[i-1]>v[i]){
//             swap(v[i-1],v[i]);
//         }
//     }
//     return bubblesort(v,n-1);
// }
// int main(){
//     vector<int> v = {11,22,3,7,4,23,2,7};
//     int n = v.size();
//     bubblesort(v,n);

//     cout<<"Sorted array:"<<endl;
//     for(int it:v)
//         cout<<it<<" ";
//     return 0;
// }




// merge sort
// #include<iostream>
// #include<vector>
// using namespace std;
// void merge(int* arr,int s,int e){
//     int mid = s+(e-s)/2;
    
//     int l1 = mid-s+1;
//     int l2 = e-mid;

//     int* arr1 = new int[l1];
//     int* arr2 = new int[l2];
//     int arrindex = s;
//     for(int i=0;i<l1;i++){
//         arr1[i] = arr[arrindex++];
//     }

//     arrindex = mid+1;
//     for(int i=0;i<l2;i++){
//         arr2[i] = arr[arrindex++];
//     }

//     int i1 = 0;
//     int i2 = 0;
//     arrindex  = s;

//     while(i1<l1 && i2<l2){
//         if(arr1[i1]<arr2[i2]){
//             arr[arrindex++] = arr1[i1++];
//         }
//         else{
//             arr[arrindex++] = arr2[i2++];
//         }
//     }
//     while(i1<l1){
//         arr[arrindex++] = arr1[i1++];
//     }
//     while(i2<l2){
//         arr[arrindex++] = arr2[i2++];
//     }

//     delete[] arr1;
//     delete[] arr2;
// }
// void mergesort(int* arr,int s,int e){
//     if(s>=e)
//         return ;
    
//     int mid = s+(e-s)/2;
//     mergesort(arr,s,mid);
//     mergesort(arr,mid+1,e);
//     merge(arr,s,e);
// }
// int main(){
//     int arr[] =  {4,3,2,-1,3,11,15,3};
//     int n = 8;

//     mergesort(arr,0,n-1);
//     for(int it:arr)
//         cout<<it<<" ";
//     return 0;
// }

/*
mergesort(0, 7)
│   ├── mergesort(0, 1)
│   │   ├── mergesort(0, 0)  → return
│   │   ├── mergesort(1, 1)  → return
│   │   └── merge(0, 1)      → [3,4]
│   ├── mergesort(2, 3)
│   │   ├── mergesort(2, 2)  → return
│   │   ├── mergesort(3, 3)  → return
│   │   └── merge(2, 3)      → [-1,2]
│   └── merge(0, 3)          → [-1,2,3,4]
├── mergesort(4, 7)
│   ├── mergesort(4, 5)
│   │   ├── mergesort(4, 4)  → return
│   │   ├── mergesort(5, 5)  → return
│   │   └── merge(4, 5)      → [3,11]
│   ├── mergesort(6, 7)
│   │   ├── mergesort(6, 6)  → return
│   │   ├── mergesort(7, 7)  → return
│   │   └── merge(6, 7)      → [3,15]
│   └── merge(4, 7)          → [3,3,11,15]
└── merge(0, 7)              → [-1,2,3,3,3,4,11,15]

*/



// Quick sort
// #include<iostream>
// #include<vector>
// using namespace std;
// int partition(vector<int>& arr,int s,int e){
//     int pivotelem = arr[s];
//     int count = 0;
//     for(int i=s+1;i<=e;i++){
//         if(arr[i] < pivotelem){
//             count++;
//         }
//     }

//     int pivotindex = s+count;
//     swap(arr[s],arr[pivotindex]);

//     int i=s,j=e;
//     while(i < pivotindex && j > pivotindex){
//         while(arr[i] < pivotelem){
//             i++;
//         }
//         while(arr[j] > pivotelem){
//             j--;
//         }

//         if(i < pivotindex && j > pivotindex){
//             swap(arr[i++],arr[j--]);
//         }
//     }
//     return pivotindex;
// }
// void quicksort(vector<int>& arr,int s,int e){
//     if(s>=e)
//         return ;
    
//     int pivotindex = partition(arr,s,e);

//     quicksort(arr,s,pivotindex-1);

//     quicksort(arr,pivotindex+1,e);
// }
// int main(){
//     // vector<int> arr = {3,6,0,6,4,9,7,3};
//     vector<int> arr = {1,4,-4,2,-1,2,6};
//     int n = arr.size();

//     cout<<"Before sorting:";
//     for(int it:arr)
//         cout<<it<<" ";
        
//     quicksort(arr,0,n-1);

//     cout<<"\nAfter sorting:";
//     for(int it:arr)
//         cout<<it<<" ";

//     return 0;
// }

/*
quicksort(0, 7)                          → pivot = 3 at index 1
├── quicksort(0, 0)                     → base case
└── quicksort(2, 7)                     → pivot = 0 at index 2
    ├── quicksort(2, 1)                → base case
    └── quicksort(3, 7)                → pivot = 6 at index 6
        ├── quicksort(3, 5)            → pivot = 4 at index 4
        │   ├── quicksort(3, 3)        → base case
        │   └── quicksort(5, 5)        → base case
        └── quicksort(7, 7)            → base case

*/


// Power set of a given set
// #include<iostream>
// #include<vector>
// using namespace std;
// void power_set(const vector<int>& arr,vector<int>& output,vector<vector<int>>& res,int index){
//     if(index == arr.size()){
//         res.push_back(output);
//         return;
//     }

//     // Excluding
//     power_set(arr,output,res,index+1);

//     //Including
//     output.push_back(arr[index]);
//     power_set(arr,output,res,index+1);
//     output.pop_back();
// }
// int main(){
//     vector<int> arr = {1,2,3};
//     vector<int> output;
//     vector<vector<int>> res;
//     power_set(arr,output,res,0);

//     for(auto row:res){
//         for(auto it:row){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

/*
power_set(index = 0, output = [])
│
├── Exclude 1
│   └── power_set(index = 1, output = [])
│       │
│       ├── Exclude 2
│       │   └── power_set(index = 2, output = [])
│       │       ├── Exclude 3 → power_set(index = 3, output = [])       → PUSH []
│       │       └── Include 3 → power_set(index = 3, output = [3])      → PUSH [3]
│       │
│       └── Include 2 → power_set(index = 2, output = [2])
│           ├── Exclude 3 → power_set(index = 3, output = [2])          → PUSH [2]
│           └── Include 3 → power_set(index = 3, output = [2, 3])       → PUSH [2, 3]
│
└── Include 1 → power_set(index = 1, output = [1])
    │
    ├── Exclude 2 → power_set(index = 2, output = [1])
    │   ├── Exclude 3 → power_set(index = 3, output = [1])              → PUSH [1]
    │   └── Include 3 → power_set(index = 3, output = [1, 3])           → PUSH [1, 3]
    │
    └── Include 2 → power_set(index = 2, output = [1, 2])
        ├── Exclude 3 → power_set(index = 3, output = [1, 2])           → PUSH [1, 2]
        └── Include 3 → power_set(index = 3, output = [1, 2, 3])        → PUSH [1, 2, 3]

*/





/*
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.
*/
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// void solve(string& digits, vector<string>& ans, string& output, string mapping[], int index) {
//     if(index >= digits.length()) {
//         ans.push_back(output);
//         return;
//     }
//     int num = digits[index] - '0';
//     string value = mapping[num];
//     for(int i = 0; i < value.length(); i++) {
//         output.push_back(value[i]);
//         solve(digits, ans, output, mapping, index + 1);
//         output.pop_back();
//     }
// }

// vector<string> letterCombinations(string digits) {
//     vector<string> ans;
//     if(digits.length() <= 0)
//         return ans;

//     string output = "";
//     string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//     solve(digits, ans, output, mapping, 0);
//     return ans;
// }

// int main() {
//     string digits = "23";
//     vector<string> result = letterCombinations(digits);

//     cout << "Possible combinations for \"" << digits << "\":" << endl;
//     for(const string& s : result) {
//         cout << s << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

/*
for digits = "23";
solve(index = 0, output = "")
├── Add 'a' → solve(index = 1, output = "a")
│   ├── Add 'd' → solve(index = 2, output = "ad") → PUSH "ad"
│   ├── Add 'e' → solve(index = 2, output = "ae") → PUSH "ae"
│   └── Add 'f' → solve(index = 2, output = "af") → PUSH "af"
├── Add 'b' → solve(index = 1, output = "b")
│   ├── Add 'd' → solve(index = 2, output = "bd") → PUSH "bd"
│   ├── Add 'e' → solve(index = 2, output = "be") → PUSH "be"
│   └── Add 'f' → solve(index = 2, output = "bf") → PUSH "bf"
└── Add 'c' → solve(index = 1, output = "c")
    ├── Add 'd' → solve(index = 2, output = "cd") → PUSH "cd"
    ├── Add 'e' → solve(index = 2, output = "ce") → PUSH "ce"
    └── Add 'f' → solve(index = 2, output = "cf") → PUSH "cf"
*/




/*
Given an array nums of distinct integers, return all the possible permutations
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void permutation(vector<int>& nums, vector<vector<int>>& ans, int index) {
//     if (index >= nums.size()) {
//         ans.push_back(nums);
//         return;
//     }

//     for (int i = index; i < nums.size(); i++) {
//         swap(nums[index], nums[i]);
//         permutation(nums, ans, index + 1);
//         swap(nums[index], nums[i]);
//     }
// }
// int main() {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> ans;
//     permutation(nums, ans, 0);

//     for (const auto& perm : ans) {
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }






/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat[][].
The rat's goal is to reach the destination at position (n-1, n-1).
The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:
    0: A blocked cell through which the rat cannot travel.
    1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination,
starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot
revisit any cell along the same path. Furthermore, the rat can only move to adjacent
cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.
*/
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;
// bool issafe(vector<vector<int>>& maze, vector<vector<int>>& visited, int x, int y, int n) {
//     if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }
// void solve(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<string>& ans, string& path, int x, int y, int n) {
//     if (x == n - 1 && y == n - 1) {
//         ans.push_back(path);
//         return;
//     }

//     visited[x][y] = 1;

//     // Down
//     int nx = x + 1;
//     int ny = y;
//     if (issafe(maze, visited, nx, ny, n)) {
//         path.push_back('D');
//         solve(maze, visited, ans, path, nx, ny, n);
//         path.pop_back();
//     }

//     // Left
//     nx = x;
//     ny = y - 1;
//     if (issafe(maze, visited, nx, ny, n)) {
//         path.push_back('L');
//         solve(maze, visited, ans, path, nx, ny, n);
//         path.pop_back();
//     }

//     // Right
//     nx = x;
//     ny = y + 1;
//     if (issafe(maze, visited, nx, ny, n)) {
//         path.push_back('R');
//         solve(maze, visited, ans, path, nx, ny, n);
//         path.pop_back();
//     }

//     // Up
//     nx = x - 1;
//     ny = y;
//     if (issafe(maze, visited, nx, ny, n)) {
//         path.push_back('U');
//         solve(maze, visited, ans, path, nx, ny, n);
//         path.pop_back();
//     }

//     visited[x][y] = 0;
// }

// vector<string> ratInMaze(vector<vector<int>>& maze) {
//     vector<string> ans;

//     if (maze[0][0] == 0)
//         return ans;
//     int n = maze.size();
//     vector<vector<int>> visited = maze;
//     for (auto& row : visited) {
//         for (int& it : row) {
//             it = 0;
//         }
//     }

//     string path = "";
//     int x = 0;
//     int y = 0;
//     solve(maze, visited, ans, path, x, y, n);
//     sort(ans.begin(),ans.end());
//     return ans;
// }

// int main() {
//     vector<vector<int>> maze = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}
//     };

//     vector<string> paths = ratInMaze(maze);

//     if (paths.empty()) {
//         cout << "-1" << endl;
//     } else {
//         for (const string& path : paths) {
//             cout << path << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }