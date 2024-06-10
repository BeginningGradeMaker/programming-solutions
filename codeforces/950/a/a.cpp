#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m; cin >> n >> m;
    vector<int> cnt(7);

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        cnt[c - 'A']++;
    }

    int ans = 0;
    for (int x : cnt) {
        ans += max(0, m - x);
    }

    cout << ans << endl;
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
