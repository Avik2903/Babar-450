#include <bits/stdc++.h>
using namespace std;

void addadj(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printadj(int V, vector<int> adj[])
{
    for (int node = 1; node <= V; node++)
    {
        cout << "Node " << node << ": ";
        for (int neighbor : adj[node])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void dfsRec(vector<int> adj[], vector<bool> &vis, int s, vector<int> &res) {

    vis[s] = true;
    res.push_back(s);
    for (auto i : adj[s])
        if (vis[i]==false)
            dfsRec(adj, vis, i, res);
}

vector<int> dfsgraph(int V, vector<int> adj[])
{
    vector<bool> vis(V+1, false);
    int start=1;
    vector<int> res;
    dfsRec(adj, vis, start, res);
    return res;
}

int main()
{
    int V = 9;
    vector<int> adj[V + 1];
    addadj(adj, 0, 1);
    addadj(adj, 1, 2);
    addadj(adj, 1, 3);
    addadj(adj, 2, 5);
    addadj(adj, 2, 6);
    addadj(adj, 3, 4);
    addadj(adj, 4, 8);
    addadj(adj, 8, 7);
    addadj(adj, 7, 3);
    //printadj(V, adj);
    vector<int> res = dfsgraph(V,adj);

    for (int i : res)
        cout << i << " ";

    return 0;
}