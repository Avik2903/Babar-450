#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, bfs(grid, i, j));
                }
            }
        }
        return area;
    }

    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j] = 0;
        q.push({i, j});
        int res = 1;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;

            for (int d = 0; d < 4; d++) {
                int rc = r + directions[d][0];
                int cc = c + directions[d][1];
                if (rc >= 0 && cc >= 0 && rc < grid.size() && cc < grid[0].size() && grid[rc][cc] == 1) {
                    q.push({rc, cc});
                    grid[rc][cc] = 0;
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    cout << solution.maxAreaOfIsland(grid) << endl;
    return 0;
}

