#include<bits/stdc++.h>
using namespace std;
void subs(int idx,vector<int>& nums,vector<int>& sub,vector<vector<int>>& res)
{
    res.push_back(sub);
    for(int i=idx;i<nums.size();i++)
    {
        if(i>idx && nums[i]==nums[i-1]) continue;
        sub.push_back(nums[i]);
        subs(i+1,nums,sub,res);
        sub.pop_back();
    }
}
int main()
{
    vector<int> nums = {1,2,1};
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    vector<int> sub;
    subs(0,nums,sub,res);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j != res[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}