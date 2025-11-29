#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n,vector<vector<int>>& flights,int src,int dst,int k)
{
    vector<pair<int,int>> adj[n];
    for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
    queue<pair<int,pair<int,int>>> q; // {stops,{node,dist}}
    q.push({0,{0,0}});
    vector<int> dist(n,1e9);
    dist[src]=0;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(stops>k)
            continue;
        for(auto iter:adj[node])
        {
            int adjnode=iter.first;
            int edw=iter.second;
            if(cost+edw<dist[adjnode] && stops<=k)
            {
                dist[adjnode]=cost+edw;
                q.push({stops+1,{adjnode,cost+edw}});
            }
        }
    }
    if(dist[dst]==1e9) return -1;
    return dist[dst];
}

int main()
{
    int n = 4, src = 0, dst = 3, K = 1;

    // Flight routes and their costs
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},{2, 3, 200}};

    // Call the method to find the cheapest flight
    int ans = CheapestFLight(n, flights, src, dst, K);

    // Output the result
    cout << ans << endl;

    return 0;
}