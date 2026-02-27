#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
using namespace std;
long long chessDistance(int n, int m, vector<string> &board) {
	vector<pair<int,int>> v;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(board[i][j] == '1')
				v.emplace_back(i+1,j+1);
		
		int size = v.size();
		long long sum = 0;
		for(int i=0;i<size-1;i++){
			auto a = v[i];
			for(int j=i+1;j<size;j++){
				auto b = v[j];
				sum+=max(abs(a.first-b.first),abs(a.second-b.second));
			}
		}	
	return sum;
}
int main() {
    int n = 3, m = 3;
    vector<string> board = {
        "101",
        "010",
        "101"
    };
    cout << chessDistance(n, m, board) << endl;
    return 0;
}
