#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m, k; cin >> n >> m >> k;
    int prev = 0;
    string s; cin >> s;
    /*cout << n << ' ' << m << ' ' << k << endl;*/
    for (int i = 1; i <= n; i++) {
        char c = s[i-1];
        if (c == 'C' && i - prev >= m) {
        /*cout << "k: " << k << endl;*/
            cout << "NO" << endl;
            return;
        }
        if (c == 'L') {
            if (i - prev - m <= k) {
                k -= max(0, i - prev - m);
                prev = i;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        /*cout << "k: " << k << endl;*/
    }
    cout << (k >= n + 1 - prev - m ? "YES" : "NO") << endl;
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
