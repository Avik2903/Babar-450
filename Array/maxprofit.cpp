#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,i,max=0,min,loc;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            loc=i;
        }
    }
    if(loc==n-1)
    return 0;
    else
    {
        for(int j=loc;j<n;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
            }
        }
    }
    cout<<max-min;
    return 0;
}