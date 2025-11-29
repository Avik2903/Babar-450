#include<bits/stdc++.h>
using namespace std;
class Disjoinset{
    vector<int> rank,parent,size;
    public:
        Disjoinset(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int findupar(int node)
        {
            if(node==parent[node])
                return node;
            
            return parent[node]=findupar(parent[node]);
        }
        
        void unionbyrank(int u,int v)
        {
            int ultp_u=findupar(u);
            int ultp_v=findupar(v);
            if(ultp_u==ultp_v)
                return;
            if(rank[ultp_u]<rank[ultp_v])
            {
                parent[ultp_u]=ultp_v;
            }
            else if(rank[ultp_v]<rank[ultp_u])
            {
                parent[ultp_v]=ultp_u;
            }
            else 
            {
                parent[ultp_v]=ultp_u;
                rank[ultp_u]++;
            }
        }

        void unionbysize(int u,int v)
        {
            int ultp_u=findupar(u);
            int ultp_v=findupar(v);
            if(ultp_u==ultp_v) return;
            if(size[ultp_u]<size[ultp_v])
            {
                parent[ultp_u]=ultp_v;
                size[ultp_v]+=size[ultp_u];
            }
            else
            {
                parent[ultp_v]=ultp_u;
                size[ultp_u]+=size[ultp_v];
            }
        }
};
int main()
{
    Disjoinset ds(7);
    // ds.unionbyrank(1,2);
    // ds.unionbyrank(2,3);
    // ds.unionbyrank(4,5);
    // ds.unionbyrank(6,7);
    // ds.unionbyrank(5,6);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    // if 3 and 7 same or not
    cout<<boolalpha<<(ds.findupar(3)==ds.findupar(7))<<endl;
    //ds.unionbyrank(3,7);
    ds.unionbysize(3,7);
    cout<<boolalpha<<(ds.findupar(3)==ds.findupar(7))<<endl;
    return 0;
}