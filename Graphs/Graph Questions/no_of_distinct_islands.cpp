#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int baser,int basec,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>>& shape)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[i][j]=1;
    shape.push_back({i-baser,j-basec});
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int x=0;x<4;x++)
    {
        int nrow=i+dx[x];
        int ncol=j+dy[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
        {
            dfs(nrow,ncol,baser,basec,grid,vis,shape);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> s;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && !vis[i][j])
            {
                vector<pair<int,int>> shape;
                dfs(i,j,i,j,grid,vis,shape);
                s.insert(shape);
            }
        }
    }
    return s.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
    };
    cout <<countDistinctIslands(grid);
    return 0;
}