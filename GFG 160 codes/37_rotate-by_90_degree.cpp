/*
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90
degrees in an anti-clockwise direction without using any extra space. 
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void rotateby90(vector<vector<int>>& mat){
//     int n = mat.size();
//     for(int i = 0; i < n; i++)
//         reverse(mat[i].begin(), mat[i].end());

//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++) {
//             swap(mat[i][j], mat[j][i]);
//         }
//     }
// }
// int main() {
//     vector<vector<int>> mat = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     rotateby90(mat);

//     for(const auto& row : mat) {
//         for(int val : row)
//             cout << val << " ";
//         cout << endl;
//     }
//     return 0;
// }





/*
You are given an n x n 2D matrix representing an
image, rotate the image by 90 degrees (clockwise).
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     for(int i = 0; i < n / 2; i++) {
//         swap(matrix[i], matrix[n - i - 1]);
//     }

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             swap(matrix[i][j], matrix[j][i]);
//         }
//     }
// }
// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     rotate(matrix);

//     for(const auto& row : matrix) {
//         for(int val : row)
//             cout << val << " ";
//         cout << endl;
//     }
//     return 0;
// }