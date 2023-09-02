#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > result;
bool isSafe(vector<vector<int> > board,
			int row, int col)
{
	int x=row;
    int y=col;
    int n=board.size();
    while(y>=0)
    {
        if(board[x][y]==1)
            return false;
        y--;
    }
    x=row;
    y=col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;
        y--;
        x--;
    }
    x=row;
    y=col;
    while(x<n && y>=0)
    {
        if(board[x][y]==1)
            return false;
        y--;
        x++;
    }
    return true;
}

bool solve(vector<vector<int> >& board, int col)
{
	int N = board.size();
	if (col == N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return true;
	}
	bool res = false;
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			res = solve(board, col + 1) || res;
			board[i][col] = 0; // BACKTRACK
		}
	}
	return res;
}

vector<vector<int> > nQueen(int n)
{
	result.clear();
	vector<vector<int> > board(n, vector<int>(n, 0));

	if (solve(board, 0) == false) {
		return {};
	}

	sort(result.begin(), result.end());
	return result;
}

int main()
{
	int n = 4;
	vector<vector<int> > v = nQueen(n);

	for (auto ar : v) {
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]";
	}

	return 0;
}
