#include <bits/stdc++.h>
using namespace std;
#define N 4
void rotate(int arr[N][N])
{
	for (int j=0;j<N;j++)
	{
		for (int i=N-1;i>=0;i--)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
	rotate(arr);
	return 0;
}