#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<vector<int>>& a) {
    return a[i][j] + max((i ? f(i - 1, j, a) : 0), (j ? f(i, j - 1, a) : 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << f(n - 1, m - 1, a) << "\n";
    return 0;
}