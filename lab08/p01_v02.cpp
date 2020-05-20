#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int>& t) {
    return n < 0 ? 0 : t[n] ? t[n] : n == 0 ? 1 : t[n] = f(n - 1, t) + f(n - 2, t) + f(n - 3, t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> t(n + 1, 0);
    cout << f(n, t) << "\n";
    return 0;
}