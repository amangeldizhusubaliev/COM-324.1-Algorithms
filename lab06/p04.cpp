#include <bits/stdc++.h>

using namespace std;

int di[] = {-1,  0, +1,  0};
int dj[] = { 0, -1,  0, +1};

void bfs(int si, int sj, int ei, int ej, vector<vector<char>>& a) {
    queue<int> qi, qj;
    vector<vector<int>> d(a.size(), vector<int>(a.size(), int(1e9)));
    vector<vector<pair<int, int>>> p(a.size(), vector<pair<int, int>>(a.size()));
    d[si][sj] = 0;
    qi.push(si); qj.push(sj);
    while (!qi.empty()) {
        int vi = qi.front(); qi.pop();
        int vj = qj.front(); qj.pop();
        for (int i = 0; i < 4; i++) {
            int gi = vi + di[i];
            int gj = vj + dj[i];
            if (gi >= 0 && gi < a.size() && gj >= 0 && gj <= a.size() && 
                        a[gi][gj] != '#' && d[gi][gj] > d[vi][vj] + 1) {
                d[gi][gj] = d[vi][vj] + 1;
                p[gi][gj] = make_pair(vi, vj);
                qi.push(gi); qj.push(gj);
            }
        }
    }
    for (int i = ei, j = ej; i != si || j != sj; ) {
        a[i][j] = '*';
        auto tmp = p[i][j]; i = tmp.first; j = tmp.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                si = i; sj = j;
            }
            if (a[i][j] == 'D') {
                ei = i; ej = j;
            }
        }
    }
    bfs(si, sj, ei, ej, a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}