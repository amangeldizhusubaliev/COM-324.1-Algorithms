#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= min(n, i + 3); j++) {
            dp[j] += dp[i];
        }
    }    
    cout << dp[n] << "\n";
    return 0;
}