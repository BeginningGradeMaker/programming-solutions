#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;
#define endl '\n'

void solve() {
    // Solution goes here
    int n; cin >> n;

    // Let f(x) be the number of elements >= x
    // Claim: f(x) <= n^2 - (x-1)^2
    // Base case: x = 1. Holds since every element >= 1
    // Inductive: if the last operation is on row, then
    // that row has x - 1 elements < x and n - x + 1
    // elements >= x. The remaing grid should have at most
    // (n-1)n - (x-1)(x-2) elements >= x by the inductive 
    // hypothesis, adding them up gives n^2 - (x-1)^2.
    // Similar if the last operation is on column.
    //
    // Note that sum = f(1) + ... + f(n)
    ll ans = 0;
    ans += n * n * n;
    for (ll x = 1; x <= n; x++) {
        ans -= (x-1) * (x-1);
    }

    cout << ans << ' ' << 2 * n - 1 << endl;
    for (int i = 2 * n - 2; i >= 0; i--) {
        if (i % 2 == 0) {
            cout << 1 << ' ' << i / 2 + 1 << ' ';
        } else {
            cout << 2 << ' ' << i / 2 + 1 << ' ';
        }

        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << endl;
    }
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
