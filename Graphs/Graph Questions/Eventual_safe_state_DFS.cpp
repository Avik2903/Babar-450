#include<bits/stdc++.h>
using namespace std;

bool dfs(int curNode, vector<bool>& visited, vector<bool>& safe, vector<vector<int>>& adj) {
    // Mark current node as visited
    visited[curNode] = true;

    // Assume the node is safe until proven otherwise
    bool isSafe = true;

    // Exploring all paths
    for (auto nextNode : adj[curNode]) {
        if (!visited[nextNode]) {
            isSafe &= dfs(nextNode, visited, safe, adj);
        }
        // If the adjacent node is already visited and not safe,
        // it means the current node is part of a cycle
        else if (!safe[nextNode]) {
            isSafe = false;
            break;
        }
    }
    return safe[curNode] = isSafe;
}

vector<int> safeNodes(vector<vector<int>>& adj)
{
    int v = adj.size();
    vector<int> ans;
    vector<bool> visited(v, false);
    vector<bool> safe(v, false);

    // Perform DFS for each unvisited node
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, visited, safe, adj);
        }
    }

    // Collect all safe nodes
    for (int i = 0; i < v; i++) {
        if (safe[i]) ans.push_back(i);
    }

    return ans;
}

void addEdge(vector<vector<int>>& adj,int u,int v)
{
    adj[u].push_back(v);
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);
    
    // creating adjacency list
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    vector<int> res = safeNodes(adj);
    
    for (int vertex : res)
        cout << vertex << " ";
        
    cout << endl;
}