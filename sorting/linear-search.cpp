#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={-10, -5, 3, 4, 7, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=0;
    for(int i=0;i<n;i++)
    {
        if(i==arr[i])
        {
            cout<<i;
            a=1;
        }
    }
    if(a==0)
    cout<<"-1";
    return 0;
}