#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int ans = INT_MAX;
    int mn = min(x1, min(x2, x3));
    int mx = max(x1, max(x2, x3));

    for (int i = mn; i <= mx; i++) {
        ans = min(ans, abs(x1 - i) + abs(x2 - i) + abs(x3 - i));
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
