#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
    // Solution goes here
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n+1);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n + 1; i++) cin >> b[i];

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    
    ll mx = LLONG_MIN;
    ll mn = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }
    /*cout << mx << ' ' << mn << endl;*/

    bool ok = false;
    for (ll i = 0; i < n; i++) {
        if (b[n] <= max(a[i], b[i]) && b[n] >= min(a[i], b[i])) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        ll x = LLONG_MAX;
        /*cout << "haha: " << ans <<  endl;*/
        for (ll i = 0; i < n; i++) {
            x = min(x, min(abs(a[i] - b[n]), abs(b[i] - b[n])));
        }
        ans += x;
    }
    ans++;
    
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
