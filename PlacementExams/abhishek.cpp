#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0,x=0;
    sum=(n*(n+1))/2;
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
    {
        x+=arr[i];
    }
    cout<<x;
return 0;
}