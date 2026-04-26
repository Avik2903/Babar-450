#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int l,int mid,int r)
{
    vector<int> temp;
    int left=l;
    int right=mid+1;
    while(left<=mid && right<=r)
    {
        if(arr[left]<=arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while(left<=mid)
        temp.push_back(arr[left++]);
    while(right<=r)
        temp.push_back(arr[right++]);

    for(int i=l;i<=r;i++)
        arr[i]=temp[i-l];
}
void mergesort(vector<int> &arr,int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main()
{
    vector<int> arr={2,1,6,8,4};
    int n=arr.size();
    mergesort(arr,0,n-1);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}