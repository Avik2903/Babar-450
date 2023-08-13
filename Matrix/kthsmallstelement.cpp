#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
#define loop for(int i=0;i<R;i++)
#define loop2 for(int j=0;j<C;j++)
int main(){
    int arr[R*C];
    int c=0;
    int A[R][C];
    loop
    {
        loop2
        {
            cin>>A[i][j];
            arr[c]=A[i][j];
            c++;
        }
    }
    sort(arr,arr+(R*C));
    int k;
    cin>>k;
        cout<<arr[k-1]<<endl;
    return 0;
}