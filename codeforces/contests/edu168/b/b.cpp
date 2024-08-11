#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<vector<bool>> G(2, vector<bool>(n));
    for (int i = 0; i < 2; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            G[i][j] = s[j] == '.' ? true : false;
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < n-1; j++) {
            if (G[i][j-1] && G[i][j+1] && G[1-i][j] && !G[1-i][j+1] && !G[1-i][j-1]) {
                ans++;
            }
        }
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
