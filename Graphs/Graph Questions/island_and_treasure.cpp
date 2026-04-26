#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for (int d = 0; d < 4; d++) {
                int r = row + dirs[d][0];
                int c = col + dirs[d][1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    solution.islandsAndTreasure(grid);

    for (const auto& row : grid) {
        for (int val : row) {
            if (val == INT_MAX) {
                cout << "INF ";
            } else {
                cout << val << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}

