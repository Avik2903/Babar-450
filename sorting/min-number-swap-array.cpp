#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int indexOf(vector<int>& arr, int ele)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == ele) {
			return i;
		}
	}
	return -1;
}

// Return the minimum number
// of swaps required to sort the array
int minSwaps(vector<int> arr, int N)
{
	int ans = 0;
	vector<int> temp(arr.begin(), arr.end());
	sort(temp.begin(), temp.end());

	for (int i = 0; i < N; i++) {

		// This is checking whether
		// the current element is
		// at the right place or not
		if (arr[i] != temp[i]) {
			ans++;

			// Swap the current element
			// with the right index
			// so that arr[0] to arr[i] is sorted
			swap(arr, i, indexOf(arr, temp[i]));
		}
	}
	return ans;
}

// Driver Code
int main()
{

	vector<int> a
		= { 101, 758, 315, 730, 472, 619, 460, 479 };

	int n = a.size();

	// Output will be 5
	cout << minSwaps(a, n);
}