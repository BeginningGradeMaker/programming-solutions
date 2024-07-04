#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = a[i][j];
                bool b = true;
                if (i > 0 && a[i-1][j] >= x) b = false;
                if (i < n-1 && a[i+1][j] >= x) b = false;
                if (j > 0 && a[i][j-1] >= x) b = false;
                if (j < m-1 && a[i][j+1] >= x) b = false;
                if (b) {
                    int mn = INT_MIN;
                    if (i > 0) mn = max(mn, a[i-1][j]);
                    if (j > 0) mn = max(mn, a[i][j-1]);
                    if (i < n-1) mn = max(mn, a[i+1][j]);
                    if (j < m-1) mn = max(mn, a[i][j+1]);
                    a[i][j] = mn;
                    ok = true;
                    /*break;*/
                }
            }
            /*if (ok) {*/
            /*    break;*/
            /*}*/
        }
        /*if (ok) {*/
        /*    break;*/
        /*}*/

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
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
