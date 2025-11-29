#include <bits/stdc++.h>
using namespace std;
class Disjoint
{
    vector<int> rank, size, parent;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int finduparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = finduparent(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int ulu = finduparent(u);
        int ulv = finduparent(v);
        if (ulu == ulv)
            return;
        if (rank[ulu] < rank[ulv])
        {
            parent[ulu] = ulv;
        }
        else if (rank[ulv] < rank[ulu])
        {
            parent[ulv] = ulu;
        }
        else
        {
            parent[ulv] = ulu;
            rank[ulu]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int ulu = finduparent(u);
        int ulv = finduparent(v);
        if (ulu == ulv)
            return;
        if (size[ulu] < size[ulv])
        {
            parent[ulu] = ulv;
            size[ulv] += size[ulu];
        }
        else
        {
            parent[ulv] = ulu;
            size[ulu] += size[ulv];
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    Disjoint ds(n);
    for (auto &edge : connections)
        ds.unionbysize(edge[0], edge[1]);

    unordered_set<int> components;
    for (int i = 0; i < n; i++)
        components.insert(ds.finduparent(i));

    return components.size() - 1;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << makeConnected(n, connections) << endl;
    return 0;
}