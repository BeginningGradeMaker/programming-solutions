#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> H(n, vector<int>(m));
    vector<vector<bool>> cap(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> H[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            cap[i][j] = s[i] == '1';
        }
    }
    vector<vector<int>> pre0(n - k + 1, vector<int>(m));
    vector<vector<int>> pre1(n - k + 1, vector<int>(m));
    for (int j = 0; j < m; j++) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (cap[i][j]) {
                sum1 += H[i][j];
            } else {
                sum0 += H[i][j];
            }
        }
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
