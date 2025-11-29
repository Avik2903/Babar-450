#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &img, int x,
         int y, int oldColor, int newColor)
{

    if (x < 0 || x >= img.size() ||
        y < 0 || y >= img[0].size() || img[x][y] != oldColor)
    {
        return;
    }

    // Update the color of the current pixel
    img[x][y] = newColor;

    // Recursively visit all 4 connected neighbors
    dfs(img, x + 1, y, oldColor, newColor);
    dfs(img, x - 1, y, oldColor, newColor);
    dfs(img, x, y + 1, oldColor, newColor);
    dfs(img, x, y - 1, oldColor, newColor);
}

vector<vector<int>> floodfill(vector<vector<int>> &adj, int newc, int sr, int sc)
{
    if(adj[sr][sc]==newc)
        return adj;
    int old=adj[sr][sc];
    dfs(adj,sr,sc,old,newc);

    return adj;
}

int main()
{
    int sr = 1;
    int sc = 2;
    int newc = 2;
    vector<vector<int>> adj = {{1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};

    vector<vector<int>> res = floodfill(adj, newc, sr, sc);
    for (auto& i : res)
    {
        for (auto& row : i)
        {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}