#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    int m; cin >> m;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }   
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    vector<int> ans;
    for (int i = n, j = m; dp[i][j]; ) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1 && a[i] == b[j]) {
            ans.emplace_back(a[i]);
            i--; j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}