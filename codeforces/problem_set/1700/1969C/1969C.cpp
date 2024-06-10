#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
    // Solution goes here
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (ll &x : arr) cin >> x;

    // dp[i][j] = the mininum possible total sum of performing
    // at most j operations to arr[0] ... arr[i]
    // = min(dp[i-d][j-d+1] + d * min(arr[i-d+1] ... arr[i]))
    vector<vector<ll>> dp(n, vector<ll>(k + 1));

    for (ll i = 0; i <= k; i++) {
        dp[0][i] = arr[0];
    }

    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j <= k; j++) {
            ll mn = arr[i];
            dp[i][j] = dp[i-1][j] + arr[i];
            for (ll t = 1; t <= min(j+1, i+1); t++) {
                mn = min(mn, arr[i-t+1]);
                dp[i][j] = min(dp[i][j], (t > i ? 0 : dp[i-t][j-t+1]) + mn * t);
            }
        }
    }

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j <= k; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][k] << endl;
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
