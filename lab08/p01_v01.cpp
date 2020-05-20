#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    return n < 0 ? 0 : n == 0 ? 1 : f(n - 1) + f(n - 2) + f(n - 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << f(n) << "\n";
    return 0;
}