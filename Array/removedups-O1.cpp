/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)
    cin>>a[i];
    for(int i =0;i<n;i++)
    {
        a[a[i]%n]+=n;
    }
    for(int i =0;i<n;i++){
        if(a[i]>=n*2)
        cout<<i<<" ";
    }
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])]>=0)
        a[abs(a[i])]=-a[abs(a[i])];
        else
        cout<<abs(a[i])<<" ";
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            cout<<a[i]<<" ";
        }
    }
    return 0;
}