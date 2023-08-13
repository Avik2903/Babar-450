#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count = 0;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k=j+1;k<n;k++)
            {
                if(a[i]+a[j]+a[k]==sum)
                {
                    x=i,y=j,z=k;
                    count = 1;
                    break;
                }
                else 
                count = 0;;
            }
        if(count == 1)
            break;
        }
    if(count == 1)
        break;
    }
    cout<<a[x]<<","<<a[y]<<","<<a[z];
    if(count == 0)
    cout<<"NO";
    return 0;
}