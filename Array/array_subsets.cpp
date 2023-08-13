#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int j=0;j<m;j++)
    cin>>b[j];
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            count++;
        }
    }
    if(count==m)
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int j=0;j<m;j++)
    cin>>b[j];
    int count=0;
    int i=0,j=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (b[i] == a[j])
            {
                count = 1;
                break;
            }
        }
        if (j == m)
            count = 0;
    }
    if(count==1)
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}*/
