#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int calculateBeauty(const string &s, const vector<vector<int>> &adj, vector<int> &alphabetFreq, int node) {
    int maxFreq = 0;
    int beauty = 0;
    alphabetFreq[s[node] - 'a']++;
    for (int i = 0; i < 26; i++) {
        maxFreq = max(maxFreq, alphabetFreq[i]);
    }
    beauty = maxFreq;
    for (int neighbor : adj[node]) {
        beauty = max(beauty, calculateBeauty(s, adj, alphabetFreq, neighbor));
    }
    alphabetFreq[s[node] - 'a']--;

    return beauty;
}
int beauty(int n, int m, string s, int x[], int y[]) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[x[i] - 1].push_back(y[i] - 1);
    }
    vector<int> alphabetFreq(26, 0);
    int maxBeauty = 0;
    for (int i = 0; i < n; i++) {
        int beautyValue = calculateBeauty(s, adj, alphabetFreq, i);
        maxBeauty = max(maxBeauty, beautyValue);
    }
    if (maxBeauty >= INF) {
        return -1;
    }

    return maxBeauty;
}
namespace user {
    void testCases() {
        int x1[] = {1, 1, 3, 4};
        int y1[] = {2, 3, 4, 5};
        int result1 = beauty(5, 4, "abaca", x1, y1);
        cout << "Result 1: " << result1 << endl;
    }
}

int main() {
    user::testCases();
    return 0;
}
