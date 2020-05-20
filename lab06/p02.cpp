#include <bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<vector<int>>& g, vector<int>& u, vector<int>& ans) {
    u[v] = 1;
    for (int to : g[v]) {
        if (u[to] == 1) {
            return true;
        } else if (u[to] == 0) {
            if (dfs(to, g, u, ans)) {
                return true;
            }
        } 
    }
    u[v] = 2;
    ans.emplace_back(v);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string line; getline(cin, line);
    istringstream sinp(line);
    int n; sinp >> n;
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        sinp = istringstream(line);
        int x;
        while (sinp >> x) {
            g[i].emplace_back(--x);
        }
    }
    vector<int> u(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (u[i] == 0) {
            if (dfs(i, g, u, ans)) {
                cout << "loop\n";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "res:";
    for (int i : ans) {
        cout << " " << i + 1;
    }
    cout << "\n";
    return 0;
}