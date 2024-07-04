#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int j = i;
        for (int k = 0; k < n; k++) {
            if (j < m && a[k] == b[j]) {
                j++;
            }
        }
        ans = max(ans, j - i);
    }

    cout << (m - ans) + n << endl;
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
