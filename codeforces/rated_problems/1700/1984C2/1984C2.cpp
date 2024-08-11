#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 998244353;
ll N = 200005;

void solve() {
    // Solution goes here
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    // mn[i] = the maximum value after ith operation and the number
    // of procedures producing this value
    vector<vector<ll>> mx(n, vector<ll>(2));
    vector<vector<ll>> mn(n, vector<ll>(2));
    mn[0] = {a[0], (a[0] >= 0 ? 2 : 1)};
    mx[0] = {abs(a[0]), (a[0] >= 0 ? 2 : 1)};

    for (ll i = 1; i < n; i++) {
        // calculate maximum possible val with operations 0 ... i
        ll n1 = mx[i-1][0] + a[i];
        ll n2 = mn[i-1][0] + a[i];
        /*cout << i << ' ' << n1 << ' ' << n2 << endl;*/
        if (n1 == -n2 && n1 != 0) {
            mx[i][0] = n1;
            mx[i][1] += mx[i-1][1] * 2 + mn[i-1][1];
        } else if (n1 >= abs(n2)) {
            mx[i][0] = abs(n1);
            mx[i][1] = n1 >= 0 ? 2 * mx[i-1][1] : mx[i-1][1];
        } else {
            mx[i][0] = abs(n2);
            mx[i][1] = mn[i-1][1];
        }
        // calculate minimum possible val after ith operation
        mn[i][0] = mn[i-1][0] + a[i];
        mn[i][1] = mn[i-1][1];
        if (mn[i][0] >= 0) {
            mn[i][1] *= 2;
        }
        mn[i][1] %= mod;
        mx[i][1] %= mod;
    }

    /*for (ll i = 0; i < n; i++) {*/
    /*    cout << i; */
    /*    cout << "at " << a[i] << ", mx:(" << mx[i][0] << ' ' << mx[i][1];*/
    /*    cout << "), mn:(" << mn[i][0] << ' ' << mn[i][1] << ")" << endl;*/
    /*}*/

    cout << mx[n-1][1] % mod << endl;
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
