#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int r[k];
    for (int i = 0; i < k; i++)
        cin >> r[i];
    int j = 0, c = 0,sum=0;
    while (k > 0)
    {c=0;sum=0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= r[j])
            {
                c++;
                sum+=arr[i];
            }
        }
        cout<<c<<" "<<sum<<endl;
        k--;
        j++;
    }
    return 0;
}