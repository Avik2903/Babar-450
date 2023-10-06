#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>> &mat,int n)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    vector<int> v;
    v.push_back(mat[i][j]);
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 and ny>=0 and nx<n and ny<n and (mat[nx][ny]-mat[x][y]==1))
            {
                q.push({nx,ny});
                v.push_back(mat[nx][ny]);
            }
        }
    }
    return v.size();
}
int main()
{
    int ans=0;
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=max(ans,solve(i,j,mat,n));
        }
    }
    cout<<ans;
    return 0;
}
