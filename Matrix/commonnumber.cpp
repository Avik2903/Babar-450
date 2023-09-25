#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5
void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;
	// initialize 1st row elements with value 1
	for (int j = 0; j < N; j++)
		mp[(mat[0][j])] = 1;

	// traverse the matrix
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// If element is present in the map and
			// is not duplicated in current row.
			if (mp[(mat[i][j])] == i)
			{
			// we increment count of the element
			// in map by 1
				mp[(mat[i][j])] = i + 1;

				// If this is last row
				if (i==M-1 && mp[(mat[i][j])]==M)
				cout << mat[i][j] << " ";
			}
		}
	}
}
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}




/*#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 5
#define loop for (int i = 0; i < R; i++)
#define loop2 for (int j = 0; j < C; j++)
int main()
{
    int arr[5];
    int count = 0;
    int A[R][C];
    loop
    {
        loop2
        {
            cin >> A[i][j];
        }
    }
    int sum = 0;
    for (int z = 0; z < C; z++)
    {
        int x = A[0][z];
        sum = 0;
        for (int i = 1; i < R; i++)
        {
            loop2
            {
                if (A[i][j] == x)
                {
                    sum++;
                    break;
                }
            }
        }
        // cout<<sum;
        if (sum == R - 1)
        // cout << x << " ";
        {
            arr[count] = x;
            count++;
        }
    }
    sort(arr, arr + 3);
    for (int i = 0; i < count; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}*/
