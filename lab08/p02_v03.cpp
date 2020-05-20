#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (i) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            if (j) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            dp[i][j] += a[i][j];
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}