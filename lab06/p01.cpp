#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<int>& u, vector<int>& p) {
    p.emplace_back(v);
    u[v] = 1;
    for (int to : g[v]) {
        if (!u[to]) {
            dfs(to, g, u, p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '1') {
                g[i].emplace_back(j);
            }
        }
    }
    int cn = 0;
    vector<int> p, u(n, 0);
    for (int i = 0; i < n; i++) {
        if (u[i] == 0) {
            p.clear();
            dfs(i, g, u, p);
            cout << ++cn << ":";
            for (int j : p) {
                cout << " " << j;
            }
            cout << "\n";
        }
    }
    return 0;
}