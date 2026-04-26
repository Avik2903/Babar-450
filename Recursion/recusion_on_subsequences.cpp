#include<bits/stdc++.h>
using namespace std;
void sub(int idx,vector<int>& ans,vector<int>& arr,int n)
{
    if(idx==n)
    {
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    //pick
    ans.push_back(arr[idx]);
    sub(idx+1,ans,arr,n);
    ans.pop_back();

    //not pick
    sub(idx+1,ans,arr,n);
}
int main()
{
    vector<int> arr={1,2,3};
    int n=arr.size();
    vector<int> ans;
    sub(0,ans,arr,n);
    return 0;   
}
