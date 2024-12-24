#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    map<int, int> cnt;
    for (int color : c) {
        cnt[color]++;
    }
    int one = 0;
    int more = 0;
    for (auto [_, x] : cnt) {
        if (x == 1) one++;
        else more++;
    }
    cout << (one + 1) / 2 * 2 + more << endl;
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
