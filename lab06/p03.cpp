#include <bits/stdc++.h>

using namespace std;

void bfs(int a, int b, vector<vector<int>>& g, vector<int>& p, vector<int>& d) {
    queue<int> q;
    q.push(a);
    d[a] = 0;
    vector<int> u(d.size(), -1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
                u[to] = v;
            }
        }
    }
    for (int i = b; i != -1; i = u[i]) {
        p.emplace_back(i);
    }
    reverse(p.begin(), p.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    unordered_map<string, int> m;
    vector<string> rm;
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(0));
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (!m.count(a)) {
            m[a] = rm.size();
            rm.emplace_back(a);
        }
        if (!m.count(b)) {
            m[b] = rm.size();
            rm.emplace_back(b);
        }
        g[m[a]].emplace_back(m[b]);
        g[m[b]].emplace_back(m[a]);
    }
    cin >> a >> b;
    vector<int> p, d(rm.size(), int(1e9));
    bfs(m[a], m[b], g, p, d);
    for (int i = 0; i < rm.size(); i++) {
        cout << rm[i] << ": " << d[i] << "\n";
    }
    for (int i : p) {
        cout << " " << rm[i];
    }
    cout << "\n";
    return 0;
}