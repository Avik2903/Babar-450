#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    int i=0;
    while(ar1[m-1]>ar2[0])
    {
        if(ar1[i]>ar2[0])
        {
            swap(ar1[i],ar2[0]);
            sort(ar2,ar2+n);
        }
        i++;
    }
    for (auto x : ar1){cout<<x<<" ";} cout << endl ;
    for (auto y : ar2){cout<<y<<" ";} cout << endl ;
    return 0;
}





/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    int i=0,j=0,k=m-1;
    while(i<=k && j<n)
    {
        if(ar1[i]<ar2[j])
        {
            i++;
        }
        else
        {
            swap(ar2[j++],ar1[k--]);
        }
    }
    sort(ar1,ar1+m);
    sort(ar2,ar2+n);
    for (auto x : ar1){cout<<x<<" ";} cout << endl ;
    for (auto y : ar2){cout<<y<<" ";} cout << endl ;
    return 0;
}
*/
