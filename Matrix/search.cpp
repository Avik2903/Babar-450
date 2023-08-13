#include<bits/stdc++.h>
using namespace std;
void search(int A[4][4],int x)
{
    int c=0,m,n;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(A[i][j]==x)
            {
                c++;
                m=i;n=j;
                break;
            }
            
        }
    }
    if(c=1)
    {
        cout<<"Element found at ("<<m<<","<<n<<")";
    }
    else
    {
        cout<<"Element not found!";
    }
}
int main(){
    int A[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
        }
    }
    int x;
    cin>>x;
    cout<<"the matrix in original form"<<endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<< A[i][j]<<" ";
        }
        cout<<endl;
    }
    search(A,x);
    return 0;
}