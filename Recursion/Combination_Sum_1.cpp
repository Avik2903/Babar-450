#include<bits/stdc++.h>
using namespace std;
void comb(int i,vector<int>& nums,int tar,vector<int>& ds,vector<vector<int>>& res)
{
    int n=nums.size();
    if(i>=n)
    {
        if(0==tar)
        {
            res.push_back(ds);
        }
        return;
    }
    if(nums[i]<=tar)
    {
        ds.push_back(nums[i]);
        comb(i,nums,tar-nums[i],ds,res);
        ds.pop_back();
    }
    comb(i+1,nums,tar,ds,res);
}
int main()
{
    vector<int> nums={2,5,6,9};
    int tar=9;
    vector<vector<int>> res;
    vector<int> ds;
    comb(0,nums,tar,ds,res);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}