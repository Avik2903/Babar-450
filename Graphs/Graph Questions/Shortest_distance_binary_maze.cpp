#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid,pair<int,int>& source,pair<int,int>& destination)
{
    if(source.first==destination.first && source.second==destination.second)
        return 0;

    queue<pair<int,pair<int,int>>> q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[source.first][source.second]=0;

    q.push({0,{source.first,source.second}});
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        for(int i=0;i<4;i++)
        {
            int newr=r+dx[i];
            int newc=c+dy[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dis+1<dist[newr][newc])
            {
                dist[newr][newc]==1+dis;
                if(newr==destination.first && newc==destination.second)
                    return dis+1;
                q.push({dis+1,{newr,newc}});
            }
        }
    }
    return -1;
}

int main()
{
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    // Define the grid
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0},
                                 {1, 0, 0, 1}};

    // Call the method to find the shortest path
    int res = shortestPath(grid, source, destination);

    // Output the result
    cout << res << endl;

    return 0;
}