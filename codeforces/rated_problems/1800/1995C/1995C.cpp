#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
    // Solution goes here
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 1; i < n; i++) {
        if (a[i] == 1 && a[i-1] != 1) {
            cout << -1 << endl;
            return;
        }
    }

    // Idea: Let op[i] be the number of operations needed on a[i] to make
    // a[i-1] <= a[i]. Say op[i-1] = x, then op[i] = x + y where y is
    // the number operations to make a[i-1] just smaller than a[i] (negative) or 
    // a[i] just larger than a[i-1] (positive).
    vector<ll> op(n, 0);
    for (ll i = 1; i < n; i++) {
        ll me = a[i], him = a[i-1];

        if (him == 1) {
            op[i] = 0;
            continue;
        }

        ll cnt = 0;
        while (him * him <= me) {
            him *= him;
            cnt--;
        }

        while (me < him) {
            me *= me;
            cnt++;
        }


        op[i] = max(0ll, op[i-1] + cnt);
    }

    ll ans = 0;
    for (ll cnt : op) {
        ans += cnt;
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
