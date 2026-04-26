#include <bits/stdc++.h>
using namespace std;

int suma(int n) {
    if (n <= 0)
        return 0;
    return n + suma(n - 1);
}

int main() {
    int n = 5;
    cout << suma(n);
    return 0;
}