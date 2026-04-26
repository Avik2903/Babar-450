#include<bits/stdc++.h>
using namespace std;
void per(vector<int>& nums,vector<vector<int>> &res,int idx)
{
    if(idx==nums.size())
    {
        res.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++)
    {
        if(i>idx && nums[i]==nums[i-1]) continue;
        swap(nums[i],nums[idx]);
        per(nums,res,idx+1);
        swap(nums[i],nums[idx]);
    }
}
int main()
{
    vector<int> nums={1,1,2};
    vector<vector<int>> res;
    per(nums,res,0);
    for(auto i:res)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}