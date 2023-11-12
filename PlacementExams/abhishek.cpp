/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0,x=0;
    sum=(n*(n+1))/2;
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
    {
        x+=arr[i];
    }
    cout<<x;
return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums)
{
	int low = 1, high = nums.size() - 1, cnt;
		
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			cnt = 0;
			for(int n : nums)
			{
				if(n <= mid)
					++cnt;
			}
			// binary search on left
			if(cnt <= mid)
				low = mid + 1;
			else
			// binary search on right
				high = mid - 1;
			
		}
		return low;
}
int main()
{
	vector<int> v{ 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
	int ans = findDuplicate(v);
	cout << ans << endl;//8
	return 0;
}
