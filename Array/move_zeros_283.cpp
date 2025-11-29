#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {0,1,0,3,12};
    int last=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[last]);
            last+=1;
        }
    }
    for(auto i:a)
        cout<< i<<" ";
    
    return 0;
}