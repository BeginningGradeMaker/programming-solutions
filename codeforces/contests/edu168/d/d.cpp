#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> child(n);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        child[x-1].push_back(i);
    }

    auto dfs = [&] (auto &&dfs, int u) -> int {
        int mn = INT_MAX;
        for (int v : child[u]) {
            mn = min(mn, dfs(dfs, v));
        }

        if (mn == INT_MAX) return a[u];

        if (a[u] < mn) {
            mn = (a[u] + mn) / 2;
        }

        return mn;
    };

    int mn = INT_MAX;
    for (int v : child[0]) {
        mn = min(mn, dfs(dfs, v));
    }
    cout << a[0] + mn << endl;
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
