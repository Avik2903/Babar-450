/*#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(i=0;i<m;i++)
    cin>>b[i];
    int o;
    cin>>o;
    int c[0];
    for(i=0;i<o;i++)
    cin>>c[o];
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<o;k++)
            {
                if(a[i]==b[j] && b[j]==c[k])
                cout<<a[i]<<" ";
            }
        }
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,m,o;
    cin>>n>>m>>o;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int b[m];
    for(int j=0;j<m;j++)
    cin>>b[j];
    int c[o];
    for(int k=0;k<o;k++)
    cin>>c[k];
    int i=0,j=0,k=0;
    while(i<n && j<m && k<o)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            cout<<a[i]<<" ";
            i++;j++;k++;
        }
    else if(a[i]<b[j])
    i++;
    else if(b[j]<c[k])
    j++;
    else
    k++;
    }
    return 0;
}