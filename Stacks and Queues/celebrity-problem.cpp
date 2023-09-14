#include <bits/stdc++.h>
using namespace std;
#define N 4
int celebrity(int M[N][N], int n)
{
	int i = 0, j = n - 1;
	while (i < j) {
		if (M[j][i] == 1) 
			j--;
		else 
			i++;
	}
	int candidate = i;
	for (i = 0; i < n; i++) {
		if (i != candidate) {
			if (M[i][candidate] == 0
				|| M[candidate][i] == 1)
				return -1;
		}
	}
	return candidate;
}
int main()
{
	int M[N][N] = { { 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 1, 0 } };

	int celebIdx = celebrity(M, 4);

	if (celebIdx == -1)
		cout << ("No Celebrity");
	else {
		cout << "Celebrity ID " << celebIdx;
	}
	return 0;
}
