#include<bits/stdc++.h>
using namespace std;
void subset(int i,vector<int> &arr,vector<int> &ds,vector<vector<int>>& res,int k)
{
    if(i>=arr.size())
    {
        if(ds.size()==k)
        {
            res.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[i]);
    subset(i+1,arr,ds,res,k);
    ds.pop_back();
    subset(i+1,arr,ds,res,k);
}
int main()
{
    vector<int> arr;
    int n=3;int k=2;
    for(int i=0;i<n;i++)
        arr.push_back(i+1);
    vector<vector<int>> res;
    vector<int> ds;
    subset(0,arr,ds,res,k);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


///// Bit manipulation 
/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> comb;
            for (int bit = 0; bit < n; ++bit) {
                if (mask & (1 << bit)) {
                    comb.push_back(bit + 1);
                }
            }
            if (comb.size() == k) {
                res.push_back(comb);
            }
        }
        return res;
    }
};*/