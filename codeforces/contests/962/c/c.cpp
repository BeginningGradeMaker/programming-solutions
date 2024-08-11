#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> cnt_a(26, vector<int>(n));
    vector<vector<int>> cnt_b(26, vector<int>(n));
    cnt_a[a[0]-'a'][0]++;
    cnt_b[b[0]-'a'][0]++;
    for (int i = 1; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            cnt_a[c][i] = cnt_a[c][i-1] + (a[i] == (char)('a' + c));
            cnt_b[c][i] = cnt_b[c][i-1] + (b[i] == (char)('a' + c));
        }
    }

    /*for (int i = 0; i < n; i++) {*/
    /*    for (int c = 0; c < 26; c++) {*/
    /*        cout << cnt_a[c][i] << ' ';*/
    /*    }*/
    /*    cout << endl;*/
    /*}*/

    for (int t = 0; t < q; t++) {
        int l, r; cin >> l >> r;
        l--; r--;
        vector<int> f1(26), f2(26);
        for (int i = 0; i < 26; i++) {
            f1[i] = l == 0 ? cnt_a[i][r] : cnt_a[i][r] - cnt_a[i][l-1];
            f2[i] = l == 0 ? cnt_b[i][r] : cnt_b[i][r] - cnt_b[i][l-1];
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += abs(f1[i] - f2[i]);
        }
        cout << cnt / 2 << endl;
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
