#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> dp(n + 1, n + 1);
    vector<int> p(n + 1, -1);
    vector<int> a(n + 2);
    dp[0] = 0; a[n + 1] = int(1e9);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int l = 0, r = n; 
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (a[dp[m]] >= a[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        p[i] = dp[l];
        dp[l + 1] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (dp[i] <= n) {
            vector<int> ans;
            for (int j = dp[i]; j != 0; j = p[j]) {
                ans.emplace_back(a[j]);
            }
            reverse(ans.begin(), ans.end());
            for (int j : ans) {
                cout << j << " ";
            }
            cout << "\n";
            break;
        }
    }
    return 0;
}