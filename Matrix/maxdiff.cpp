#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
void findmax(int mat[R][C])
{
    int c=0;
    for(int i=0;i<R-1;i++)
    {
        for(int j=0;j<C-1;j++)
        {
            for(int d=i+1;d<R;d++)
            {
                for(int e=j+1;e<C;e++)
                {
                    if(c<(mat[d][e]-mat[i][j]))
                    {
                        c=(mat[d][e]-mat[i][j]);
                    }
                }
            }
        }
    }
    cout<<c;
}
int main()
{
    int mat[R][C];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>mat[i][j];
        }
    }
    findmax(mat);
    return 0;
}