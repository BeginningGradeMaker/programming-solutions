#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, x; cin >> n >> x;
    vector<int> p(n);

    for (int &num : p) cin >> num;

    int l = 0;
    int r = n;
    while (r - l != 1) {
        int m = (r + l) / 2;

        if (p[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    if (p[l] == x) {
        cout << 0 << endl;
        return;
    }

    // Swap x to pos l
    int x_pos;
    for (int i = 0; i < n; i++) {
        if (p[i] == x) {
            x_pos = i;
            break;
        }
    }

    cout << 1 << endl;
    cout << x_pos + 1 << ' ' << l + 1 << endl;
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
