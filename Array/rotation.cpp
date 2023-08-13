#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[],int n,int k)
{
    while(k>0)
    {
        int l=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=l;
        k--;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    rotate(a,n,k);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}