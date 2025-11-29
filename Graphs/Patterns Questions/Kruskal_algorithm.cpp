#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> rank,parent;
    public:
    Disjoint(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int finduparent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=finduparent(parent[node]);
    }

    void unionbyrank(int u,int v)
    {
        int ul_u=finduparent(u);
        int ul_v=finduparent(v);
        if(ul_u==ul_v) return;
        if(rank[ul_u]<rank[ul_v])
            parent[ul_u]=ul_v;
        else if(rank[ul_v]<rank[ul_u])
            parent[ul_v]=ul_u;
        else
        {
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }
};

int spanningTree(int V,vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>> edges;

    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            int v = it[0]; // Node v
            int wt = it[1]; // edge weight
            int u = i; // Node u
            edges.push_back({wt, {u, v}});
        }
    }
    Disjoint ds(V);
    sort(edges.begin(),edges.end());
    int sum=0;
    for(auto it:edges)
    {
        int wt = it.first; // edge weight
        int u = it.second.first; // First node
        int v = it.second.second; // Second node
        if(ds.finduparent(u)!=ds.finduparent(v))
        {
            sum+=wt;
            ds.unionbyrank(u,v);
        }
    }
    return sum;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };
    
    // Forming the adjacency list from edges
    vector<vector<int>> adj[4];
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    
    /* Function call to get the sum 
    of weights of edges in MST */
    int ans = spanningTree(V, adj);
    
    cout << "The sum of weights of edges in MST is: " << ans;
    
    return 0;
}