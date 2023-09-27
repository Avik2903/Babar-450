#include<bits/stdc++.h>
using namespace std;
void maxnum(vector<int>arr)
{
    string s="";
    for(int i=0;i<arr.size();i++)
    {
        s+=to_string(arr[i]);
    }
    cout<<s<<endl;
    sort(s.rbegin(),s.rend());
    cout<<s<<endl;
}
int main()
{
    vector<int>arr= {93,7,9,53,45};
    maxnum(arr);
    return 0;
}