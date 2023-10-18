#include<bits/stdc++.h>
using namespace std;
void insert(int arr[],int n)
{
    int i,j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={5,4,7,2,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    insert(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

//Insertion Sort	n	n^{2}	n^{2}	space=1	stable=Yes

