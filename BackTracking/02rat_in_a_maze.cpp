/*
Problem statement
You are given a starting position for a rat which is stuck in a maze at an initial point
(0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the
form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s
blocked locations while value 1 is the open/available path that the rat can take to reach its
destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible
paths that the rat can take to reach from source to destination in the maze. The possible directions
that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) ,
'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y)
*/


#include <bits/stdc++.h> 
using namespace std;

// Tc: O(4^(n*n))
// SC: O(n*n)
bool issafe(int x, int y, vector < vector < int >> & arr , int n, vector<vector<bool>>& vis) {
    if(((x >= 0 && x < n) && (y >= 0 && y < n)) && (arr[x][y] == 1) && (vis[x][y] == 0))
        return true;
    else
        false;
}

void solve(int x, int y, vector < vector < int >> & arr , vector<string>& ans, int n, vector<vector<bool>>& vis, string path) {
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    vector<vector<int>> Coord = {{x+1, y}, {x, y-1}, {x, y+1}, {x-1, y}};
    char* P = "DLRU";

    for(int i = 0; i < 4; i++, P++) {
        if(issafe(Coord[i][0], Coord[i][1], arr, n, vis)) 
            solve(Coord[i][0], Coord[i][1], arr, ans, n, vis, path + *P);
    }
    vis[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<bool>> vis(n, vector<bool>(n,0));
    vector<string> ans;
    string path = "";

    if(arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, ans, n, vis, path);
    return ans;
}