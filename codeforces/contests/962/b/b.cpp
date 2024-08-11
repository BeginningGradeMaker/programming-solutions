#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, k; cin >> n >> k;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) {
            cout << grid[i][j]; 
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
