#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    // (201), (210)
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if ((a[i][j] + 1) % 3 == b[i][j]) {
                a[i][j]++; a[i][j] %= 3;
                a[i+1][j+1]++; a[i+1][j+1] %= 3;
                a[i+1][j] += 2; a[i+1][j] %= 3;
                a[i][j+1] += 2; a[i][j+1] %= 3;
            } else if ((a[i][j] + 2) % 3 == b[i][j]) {
                a[i][j] += 2; a[i][j] %= 3;
                a[i+1][j+1] += 2; a[i+1][j+1] %= 3;
                a[i+1][j]++; a[i+1][j] %= 3;
                a[i][j+1]++; a[i][j+1] %= 3;
            }
        }
    }


    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i][m-1] != b[i][m-1]) {
            ok = false;
            break;
        }
    }
    for (int j = 0; j < m; j++) {
        if (a[n-1][j] != b[n-1][j]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
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
