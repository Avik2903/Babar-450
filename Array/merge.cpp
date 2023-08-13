#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m],c[n+m];
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i =0;i<m;i++)
    {
        cin>>b[i];
        c[i+n]=b[i];
    }
    sort(c,c+n+m);
    for(int i=0;i<m+n;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
