#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]}); // Add edge from node1 to node2 with weight
        adj[it[1]].push_back({it[0], it[2]}); // Add edge from node2 to node1 with weight (undirected graph)
    }

    // Create a priority queue to store {distance, node} and retrieve the node with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array to store shortest distances from the source node and parent array to track the path
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i; // Initialize the parent array to track the path from the source

    dist[1] = 0; // The distance from the source node to itself is 0

    // Push the source node (node 1) with distance 0 into the priority queue
    pq.push({0, 1});
    while (!pq.empty())
    {
        // Get the node with the minimum distance
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        // Iterate through the adjacent nodes of the current node
        for (auto it : adj[node])
        {
            int adjNode = it.first; // Adjacent node
            int edW = it.second;    // Edge weight

            // If the new computed distance is smaller, update the distance and parent
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});

                // Update the parent of adjNode to the current node
                parent[adjNode] = node;
            }
        }
    }

    // If there's no path to the destination node, return {-1}
    if (dist[n] == 1e9)
        return {-1};

    // Store the final path in the 'path' array by backtracking from the destination node
    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node); // Add node to path
        node = parent[node];  // Move to the parent node
    }
    path.push_back(1); // Add the source node to the path

    // Reverse the path to get the correct order from source to destination
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    // Driver Code

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    // Find the shortest path
    vector<int> path = shortestPath(V, E, edges);

    // Output the path
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}