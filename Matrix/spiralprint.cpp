#include <bits/stdc++.h>
using namespace std;
void spiral(int A[4][4], int m, int n)
{
    int i, k = 0, l = 0;
    while (k < m && l < n)
    {
        for (int i = l; i < n; i++)
        {
            cout << A[k][i] << " ";
        }
        k++;
        for (int i = k; i < m; i++)
        {
            cout << A[i][n - 1] << " ";
        }
        n--;
        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
            {
                cout << A[m - 1][i] << " ";
            }
            m--;
        }
        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
            {
                cout << A[i][l] << " ";
            }
            l++;
        }
    }
}
int main()
{
    int A[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
        }
    }
    cout<<"the matrix in original form"<<endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<< A[i][j]<<" ";
        }
        cout<<endl;
    }
    spiral(A, 4, 4);
    return 0;
}