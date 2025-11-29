#include<bits/stdc++.h>
using namespace std;

int findCity(int n,int m, vector<vector<int>>& edges,int t)
{
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(auto it:edges)
    {
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[2]]=it[2];
    }
    for(int i=0;i<n;i++)  
        dist[i][i]=0;

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int cntcity =n;
    int cityno=-1;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]<=t)
                cnt+=1;
        }
        if(cnt<=cntcity)
        {
            cntcity=cnt;
            cityno=i;
        }
    }
    return cityno;
}

int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    int cityNo = findCity(n, m, edges, distanceThreshold);

    // Output the result
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}