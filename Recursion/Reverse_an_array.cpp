#include<bits/stdc++.h>
using namespace std;
void rev(vector<int> &arr,int i,int n)
{
    if (i >= n) return;
    swap(arr[i],arr[n]);
    rev(arr,i+1,n-1);
}
int main()
{
    vector<int> arr={1,2,5,4,6};
    int n=arr.size()-1;
    rev(arr,0,n);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}