#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,2,3,3,3,5,5,5,5,7,8,9};
    int k;
    cin>>k;
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=INT_MIN,b=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(k!=arr[i])
            continue;
        if(a==INT_MIN)
            a=i;
        b=i;
    }
    cout<<a<<" "<<b;
    return 0;
} 





/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,2,3,3,3,5,5,5,5,7,8,9};
    int k;
    cin>>k;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans[2],j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1] && arr[i]==k)
        {
            ans[0]=i;
            j=i;
            break;
        }
        else if(arr[i]!=arr[i+1] && arr[i]==k)
        {
            ans[0]=i;
            ans[1]=i;
        }
    }
    for(int x=j;x<n;x++)
    {
        if(arr[x]!=arr[x+1] && arr[x]==k)
        {
            ans[1]=max(x,ans[0]);
            x++;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}*/