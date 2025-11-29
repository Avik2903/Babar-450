#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        int len=q.size();
        while(len--)
        {
            int x=q.front().first;
            int y=q.front().second;
            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=x+dx[i];
                int ncol=y+dy[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && ans[nrow][ncol]==INT_MAX)
                {
                    ans[nrow][ncol]=ans[x][y]+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    return ans;

}

int main() {
    vector<vector<int>> grid = {{0,1,1,0}, {1,1,0,0}, {0,0,1,1}};
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}