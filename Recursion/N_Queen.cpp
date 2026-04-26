#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve N-Queens problem
    void solve(int col, vector<string>& board, int n,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal,
               vector<vector<string>>& ans) {
        // If all queens are placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Iterate through all rows
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    int n = 4;
    vector<vector<string>> res = obj.solveNQueens(n);
    for (auto& board : res) {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}



//// hashset
/*class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);
        return res;
    }

private:
    void backtrack(int r, int n, vector<string>& board) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r + c) ||
                negDiag.count(r - c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, board);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};*/