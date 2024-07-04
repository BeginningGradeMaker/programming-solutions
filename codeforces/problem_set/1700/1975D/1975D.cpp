#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, a, b; cin >> n >> a >> b;
    a--; b--;
    vector<vector<int>> nbr(n); 
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        nbr[x-1].push_back(y-1);
        nbr[y-1].push_back(x-1);
    }

    vector<int> d(n, 0);
    vector<int> p(n, -1);
    queue<int> Q;
    unordered_set<int> S;
    S.insert(a);
    Q.push(a);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int v : nbr[u]) {
            if (v != p[u] && !S.count(v)) {
                Q.push(v);
                S.insert(v);
                p[v] = u;
                d[v] = d[u] + 1;
            }
        }
    }

    int root = b;
    for (int i = 0; i < (d[b] + 1) / 2; i++) {
        root = p[root];
    }
    /*cout << "root: " << root + 1 << endl;*/
    /*cout << "d[b]: " << d[b] / 2 << endl;*/

    auto dfs = [&] (auto &&dfs, int v, int p) -> int {
        int mx = 0;
        for (int u : nbr[v]) {
            if (u != p) {
                mx = max(mx, dfs(dfs, u, v) + 1);
            }
        }

        return mx;
    };

    cout <<  (n - 1) * 2 - dfs(dfs, root, -1) + (d[b] + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
