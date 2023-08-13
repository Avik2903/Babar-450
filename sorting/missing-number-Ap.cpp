#include<bits/stdc++.h>
using namespace std;
int main(){
int k=0;
int arr[]={1, 6, 11, 16, 21, 31};
int n=sizeof(arr)/sizeof(arr[0]);
int dif=(arr[n-1]+arr[0])/n;
for(int i=0;i<n-1;i++)
{
    if(arr[i+1]-arr[i]>dif)
    k=i;
}
cout<<arr[k]+dif;
return 0;
}