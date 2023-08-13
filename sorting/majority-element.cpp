#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={3, 3, 4, 2, 4, 4, 2, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=n/2;
    int flag=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        if(i.second>m)
        {
            cout<<"The Majority Element is "<<i.first<<endl;
            flag=1;
        }
    }
    if(flag==0)
        {
            cout<<"No Majority Element";
        }
    return 0;
}