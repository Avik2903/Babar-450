#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];
    int arr3[n1+n2];
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
        arr3[i]=arr1[i];
    }
    for(int i =0;i<n2;i++)
    {
        cin>>arr2[i];
        arr3[i+n1]=arr2[i];
    }
    sort(arr3,arr3+n1+n2);
    if((n1+n2)%2==0)
        cout<<(arr3[(n1+n2)/2]+arr3[((n1+n2)/2)-1])/2;
    else
    cout<<arr3[(n1+n2)/2];
    return 0;
}

/*
int getMedian(int ar1[], int ar2[], int n)
{
	int j = 0;
	int i = n - 1;
	while (ar1[i] > ar2[j] && j < n && i > -1)
		swap(ar1[i--], ar2[j++]);
	sort(ar1, ar1 + n);
	sort(ar2, ar2 + n);
	return (ar1[n - 1] + ar2[0]) / 2;
}

// Driver Code
int main()
{
	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45 };

	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 == n2)
		cout << "Median is " << getMedian(ar1, ar2, n1);
	else
		cout << "Doesn't work for arrays"
			<< " of unequal size";
	getchar();
	return 0;
}

//O(nlog(n))
*/