#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr,int st,int end)
{
    queue<pair<int,int>> q;
    q.push({st,0});
    vector<int> dist(100000,1e9);
    dist[st]=0;
    int mod=100000;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int num=it.first;
        int step=it.second;
        for(auto iter:arr)
        {
            int number=iter*num % mod;
            if(step+1<dist[number])
            {
                dist[number]=step+1;
                if(number==end)
                    return step+1;
                q.push({number,step+1});
            }
        }
    }
    return -1;
}

int main()
{
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    int ans = minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}