//intersection
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int b[n];
    for(int i=0;i<m;i++)
    cin>>b[i];
    cout<<"Intersection:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            cout<<a[i]<<" ";
        }
    }
    return 0;
}*/

//union
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,temp;
    cin>>n>>m;
    int a[n],b[m],c[n+m];
    for(i=0;i<n;i++)
    {cin>>a[i];c[i]=a[i];}
    for(i=0;i<m;i++)
    {cin>>b[i];c[n+i]=b[i];}
 
    for(i=0;i<n+m-1;i++)
    {
        for(j=i+1;j<n+m;j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
    int e=c[0];
    cout<<"Union-"<<c[0]<<" ";
        for(i=1;i<n+m;i++)
        {
            if(c[i]!=e)
            {cout<<c[i]<<" ";
            e=c[i];}
        }
    return 0;
}