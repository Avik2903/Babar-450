#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int>rank,parent;
    public:
    Disjoint(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int finduparent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=finduparent(parent[node]);
    }

    void unionbyrank(int u,int v)
    {
        int ulu=finduparent(u);
        int ulv=finduparent(v);
        if(ulu==ulv)    return;
        if(rank[ulu]<rank[ulv])
        {
            parent[ulu]=ulv;
        }
        else if(rank[ulv]<rank[ulu])
        {
            parent[ulv]=ulu;
        }
        else
        {
            parent[ulv]=ulu;
            rank[ulu]++;
        }
    }
};

int numProvinces(vector<vector<int>> &adj,int V)
{
    Disjoint ds(V);

    for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                // If nodes i and j are connected and not same
                if(adj[i][j] == 1 && i != j)
                    ds.unionbyrank(i, j); // Union them
            }
        }

    int count = 0;
    for(int i = 0; i < V; i++) {
        // If node is its own parent, it's a province representative
        if(ds.finduparent(i) == i)
            count++;
    }
    return count;
}

int main()
{
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Call the function and print result
    cout << numProvinces(adj, 3) << endl;

    return 0;
}