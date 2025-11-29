#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[r][c]=1;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=r+dx[i];
        int ncol=c+dy[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,vis,grid);
        }
    }
}

vector<vector<char>> fill(vector<vector<char>> &grid )
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));

    for(int i=0;i<m;i++)
    {
        if(!vis[0][i] && grid[0][i]=='O')
        {
            dfs(0,i,vis,grid);
        }
        if(!vis[n-1][i] && grid[n-1][i]=='O')
        {
            dfs(n-1,i,vis,grid);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i][0] && grid[i][0]=='O')
        {
            dfs(i,0,vis,grid);
        }
        if(!vis[i][m-1] && grid[i][m-1]=='O')
        {
            dfs(i,m-1,vis,grid);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='O' && !vis[i][j])
                grid[i][j]='X';
        }
    }
    return grid;
}

int main()
{
     vector<vector<char>> grid = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };

    fill(grid);

    for (auto& row : grid) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}