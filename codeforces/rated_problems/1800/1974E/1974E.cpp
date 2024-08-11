#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
    // Solution goes here
    ll m, x; cin >> m >> x;
    vector<ll> c(m), h(m);
    for (ll i = 0; i < m; i++) {
        cin >> c[i] >> h[i];
    }
    ll mh = accumulate(h.begin(), h.end(), 0);

    // Let dp[m][h] be the maximum money left of buying exaclty h happiness
    // after mth month.
    // then
    // dp[m][h] = max(dp[m-1][h], dp[m-1][h-h[i]] - c[i]) + x
    // dp[0][h[0]] = x if c[0] == 0
    // dp[0][0] = 0, dp[0][j] = -1 (can't buy) 
    vector<vector<ll>> dp(m, vector<ll>(mh+1));

    dp[0][0] = x;
    for (ll i = 1; i <= mh; i++) {
        dp[0][i] = -1;
    }
    if (c[0] == 0) dp[0][h[0]] = x;
    for (ll i = 1; i < m; i++) {
        for (ll j = 0; j <= mh; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= h[i] && dp[i-1][j-h[i]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] - c[i]);
            }
            if (dp[i][j] != -1) {
                dp[i][j] += x;
            }
        }
    }

    ll ans = mh;
    while (dp[m-1][ans] == -1) {
        ans--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    ll t; cin >> t;
    while (t--) {
        solve();
    }
}
