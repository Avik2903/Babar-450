#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={20, 40, 50, 70, 70, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k,x;
    cin>>k>>x;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cout<<i;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Element Not Found";
    return 0;
}