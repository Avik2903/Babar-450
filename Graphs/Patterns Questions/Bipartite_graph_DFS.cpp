#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int s,vector<int> adj[],vector<int>& vis)
{
    vis[node]=s;
    for(auto it:adj[node])
    {
        if(vis[it]==-1)
        {
            if(dfs(it,!s,adj,vis)==false)
                return false;
        }
        else if(vis[it]==s)
            return false;
    }
    return true;
}

bool isBipartite(int V,vector<int> adj[])
{
    vector<int> vis(V,-1);

    for(int i=0;i<V;i++)
    {
        if(vis[i]==-1)
        {
            if(dfs(i,0,adj,vis)==false)
                return false;
        }
    }
    return true;
}

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
	bool ans = isBipartite(4, adj);    
	if(ans)cout << "Bipartite graph\n";
	else cout << "Not Bipartite\n";  
	
	return 0;
}