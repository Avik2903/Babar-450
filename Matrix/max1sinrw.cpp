#include<bits/stdc++.h>
using namespace std;
void maxxi(int A[4][4])
{
    int c=0,r=-1,x=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(A[i][j]==1)
            c++;
        }
        if(c > x){
            x = c ;
            r = i ;
        }
        c=0;
    }
    cout<<r;
}
int main() {
    int A[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
        }
    }
    maxxi(A);
    return 0;
}