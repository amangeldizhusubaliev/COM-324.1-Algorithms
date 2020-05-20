#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (i) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            if (j) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            dp[i][j] += x;
        }
    }
    vector<char> ans;
    for (int i = n - 1, j = m - 1; i != 0 || j != 0; ) {
        int u = -1, l = -1;
        if (i) {
            u = dp[i - 1][j];
        }
        if (j) {
            l = dp[i][j - 1];
        }
        if (u > l) {
            i--;
            ans.emplace_back('D');
        } else {
            j--;
            ans.emplace_back('R');
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
    reverse(ans.begin(), ans.end());
    for (char i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}