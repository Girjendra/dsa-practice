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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool issafe(vector<vector<int>>& maze, vector<vector<int>>& visited, int x, int y, int n) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}
void solve(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<string>& ans, string& path, int x, int y, int n) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    int nx = x + 1;
    int ny = y;
    if (issafe(maze, visited, nx, ny, n)) {
        path.push_back('D');
        solve(maze, visited, ans, path, nx, ny, n);
        path.pop_back();
    }

    // Left
    nx = x;
    ny = y - 1;
    if (issafe(maze, visited, nx, ny, n)) {
        path.push_back('L');
        solve(maze, visited, ans, path, nx, ny, n);
        path.pop_back();
    }

    // Right
    nx = x;
    ny = y + 1;
    if (issafe(maze, visited, nx, ny, n)) {
        path.push_back('R');
        solve(maze, visited, ans, path, nx, ny, n);
        path.pop_back();
    }

    // Up
    nx = x - 1;
    ny = y;
    if (issafe(maze, visited, nx, ny, n)) {
        path.push_back('U');
        solve(maze, visited, ans, path, nx, ny, n);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> ans;

    if (maze[0][0] == 0)
        return ans;
    int n = maze.size();
    vector<vector<int>> visited = maze;
    for (auto& row : visited) {
        for (int& it : row) {
            it = 0;
        }
    }

    string path = "";
    int x = 0;
    int y = 0;
    solve(maze, visited, ans, path, x, y, n);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = ratInMaze(maze);

    if (paths.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : paths) {
            cout << path << " ";
        }
        cout << endl;
    }
    return 0;
}