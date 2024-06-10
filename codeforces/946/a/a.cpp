#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int x, y; cin >> x >> y;
    int n = y / 2;
    int b = y % 2;
    x -= n * 7;
    if (b == 1) x -= 11;
    cout << n + b + (max(0, x)) / 15 + (max(0, x) % 15 != 0) << endl;
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
