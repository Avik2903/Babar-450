#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
	if (arr[low] <= arr[high]) {
		return arr[low];
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < arr[mid - 1]) {
			return arr[mid];
		}
		if (arr[mid] > arr[high]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 5, 6, 1, 2, 3, 4 };
	int N = sizeof(arr)/sizeof(arr[0]);
	cout <<findMin(arr, 0, N - 1) << endl;
	return 0;
}
