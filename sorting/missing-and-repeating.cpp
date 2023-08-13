#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={4, 3, 6, 2, 1, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        if(i.second>1)
        cout<<"The Repeating Element is "<<i.first<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
        {
            cout<<"The Missing Element is "<<i<<endl;
        }
    }
    return 0;
}