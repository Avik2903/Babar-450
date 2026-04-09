#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) // memorisation
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1)    return dp[i][j];

    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);
    return dp[i][j]=min(left,up);

}
int minpath(vector<vector<int>>& grid) // memorisation
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}

int minPathSum(vector<vector<int>> &matrix) {   // tabulation
        int n = matrix.size();
        int m = matrix[0].size();

        // Create DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // First cell initialization
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    // Calculate from top
                    int up = matrix[i][j];
                    if (i > 0) up += dp[i - 1][j];
                    else up += 1e9;

                    // Calculate from left
                    int left = matrix[i][j];
                    if (j > 0) left += dp[i][j - 1];
                    else left += 1e9;

                    // Take minimum
                    dp[i][j] = min(up, left);
                }
            }
        }

        // Return result
        return dp[n - 1][m - 1];
    }

int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    cout<<minpath(grid)<<endl;
    cout<<minPathSum(grid);
}