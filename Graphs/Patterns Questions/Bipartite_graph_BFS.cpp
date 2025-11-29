#include<bits/stdc++.h>
using namespace std;

bool check(int node,int V,vector<int> adj[],vector<int> vis)
{
    vis[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(auto i:adj[n])
        {
            if(vis[i]==-1)
            {
                vis[i]=!vis[n];
                q.push(i);
            }
            else if(vis[i]==vis[n])
            {
                return false;
            }
        }   
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
            if(check(i,V,adj,vis)==false)
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