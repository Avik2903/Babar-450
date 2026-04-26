#include<bits/stdc++.h>
using namespace std;


    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n + 1, 0);

        for (auto& t : trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (delta[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }

int main() {
    int n = 4;
    vector<vector<int>> trust = {{1, 3}, {4, 3}, {2, 3}};

    int judge = findJudge(n, trust);
    if (judge == -1) {
        cout << "No town judge found" << endl;
    } else {
        cout << "Town judge is: " << judge << endl;
    }

    return 0;
}