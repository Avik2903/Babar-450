#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v])
    {
        // If an adjacent vertex is not visited, 
        //then recur for that adjacent
        if (!visited[i])
        {
            if (dfs(i, adj, visited, v))
                return true;
        }
        
        // If an adjacent vertex is visited and is not
        //parent of current vertex,
        // then there exists a cycle in the graph.
        else if (i != parent)
            return true;
    }

    return false;
}

// Returns true if the graph contains a cycle, else false.
bool isCycle(vector<vector<int>> &adj)
{
    int V= adj.size();
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
            if (dfs(u, adj, visited, -1))
                return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    isCycle(adj) ? cout << "true" : cout << "false";

    return 0;

}