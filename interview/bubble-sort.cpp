#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        bool a=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                a=1;
            }
        }
        if(a==0)
        break;
    }

}
int main()
{
    int arr[]={5,7,3,1,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
//Bubble Sort	n	n^{2}	n^{2}	space=1	stable=Yes
