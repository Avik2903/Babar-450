#include <bits/stdc++.h>
using namespace std;
/*
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
					cnt++;
			}
			if(cnt <= mid)
				low = mid + 1;
			else
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
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto i:m)
    {
        if(i.second==2)
        {
            cout<<i.first;
        }
    }
}