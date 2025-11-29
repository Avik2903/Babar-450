#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], vector<bool> &vis) {
        // Mark current node as visited
        vis[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto n : adjList[node]) {
            if (!vis[n]) {
                dfs(n, adjList, vis);
            }
        }
    }

int numProvinces(vector<vector<int>> adj,int V)
    {
        vector<int> adjList[V+1];

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> vis(V+1,false);
        int cnt=0;
        for(int i=0;i<V;i++)
        {   
            if(!vis[i])
            {   
                cnt+=1;
                dfs(i,adjList,vis);
            }
        }
        return cnt;
    }

int main()
{
    vector<vector<int>> adj = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Number of vertices
    int V = 3;

    // Call the function and print result
    cout << numProvinces(adj, V) << endl;

    return 0;
}