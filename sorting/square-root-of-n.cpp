#include<bits/stdc++.h>
using namespace std;
int squarert(int n)
{
    if(n==0 || n==1)
        return n;
    int a=1,b=n;
    int mid=-1;
    while(a<=b)
    {
        mid=a+(b-a)/2;
        int square=mid*mid;
        if(square>n)
        b=mid-1;
        else if(square==n)
        return mid;
        else
        a=mid+1;
    }
return b;
}
int main()
{
    int n;
    cin>>n;
    cout<<squarert(n);
    return 0;
}