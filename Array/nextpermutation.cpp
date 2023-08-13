//all permutation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,s;
    cin>>a;
    do
    {
        cout<<a<<"\n";
    } while (next_permutation(a.begin(),a.end()));   ///can use prev_permutation too
    
    return 0;
}