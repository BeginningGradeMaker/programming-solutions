#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (y < -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
