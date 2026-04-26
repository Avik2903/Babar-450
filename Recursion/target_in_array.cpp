#include<bits/stdc++.h>
using namespace std;
void sub(int idx,vector<int>& ans,int s,int tar,vector<int>& arr,int n)
{
    if(idx==n)
    {
        if(s==tar)
        {
            for(auto i:ans)
                cout<<i<<" ";
                cout<<endl;
        }
        return;
    }
    
    //pick
    ans.push_back(arr[idx]);
    s+=arr[idx];
    sub(idx+1,ans,s,tar,arr,n);
    s-=arr[idx];
    ans.pop_back();

    //not pick
    sub(idx+1,ans,s,tar,arr,n);
}
int main()
{
    vector<int> arr={1,2,1};
    int n=arr.size();
    int target=2;
    vector<int> ans;
    sub(0,ans,0,target,arr,n);
    return 0;   
}
