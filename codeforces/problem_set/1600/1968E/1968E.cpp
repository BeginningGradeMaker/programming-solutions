#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    cout << 1 << ' ' << 1 << endl;
    cout << n << ' ' << n << endl;
    if (n == 2) {
        cout << endl;
        return;
    }
    cout << n << ' ' << n - 1 << endl;
    for (int i = 3; i < n; i++) {
        cout << 1 << ' ' << i << endl;
    }
    cout << endl;
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
