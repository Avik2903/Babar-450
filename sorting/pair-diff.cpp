#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={5, 20, 3, 2, 50, 80};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x,flag=0;
    cin>>x;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    if (n == 0)
        cout<<"No Pair";
    for(int i=0;i<n;i++)
    {
        if(mp.find(x+arr[i])!=mp.end())
        {
            cout<<"Pair Found at "<<arr[i]<<","<<x+arr[i];
            flag=1;
        }
    }
    if(flag==0)
    cout<<"No Pair";
    return 0;
}