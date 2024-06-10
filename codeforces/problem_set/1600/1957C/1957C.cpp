#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, k; cin >> n >> k;
    set<int> S;

    for (int i = 1; i <= n; i++) {
        S.insert(i);
    }

    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        S.erase(r);
        S.erase(c);
    }
    if (S.size() == 0) {
        cout << 1 << endl;
        return;
    }

    vector<ll> dp(S.size() + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= (int)S.size(); i++) {
        dp[i] = dp[i-1] + 2 * (i-1) * dp[i-2] % mod;
        dp[i] %= mod;
    }

    cout << dp[(int)S.size()] << endl;
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
