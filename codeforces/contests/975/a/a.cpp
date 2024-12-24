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
    int mx = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x >= mx + one) {
            mx = x;
            one = !(i & 1);
        }
    }

    // 1 2 3 4 5
    one &= (n & 1);
    cout << mx + one + n/2 << endl;
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
