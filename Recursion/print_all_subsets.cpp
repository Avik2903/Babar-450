#include<bits/stdc++.h>
using namespace std;
void subset(int i,vector<int> &arr,vector<int> &ds,vector<vector<int>>& res)
{
    if(i>=arr.size())
    {
        res.push_back(ds);
        return;
    }
    ds.push_back(arr[i]);
    subset(i+1,arr,ds,res);
    ds.pop_back();
    subset(i+1,arr,ds,res);
}
int main()
{
    vector<int> arr={1,2,3};
    vector<vector<int>> res;
    vector<int> ds;
    subset(0,arr,ds,res);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j;
        }
        cout<<endl;
    }
}