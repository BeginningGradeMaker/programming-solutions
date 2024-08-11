#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, f, k; cin >> n >> f >> k;
    f--;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int gt = 0, eq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[f]) {
            gt++;
        } else if (a[i] == a[f]) {
            eq++;
        }
    }

    if (gt >= k) {
        cout << "NO" << endl;
    } else if (gt + eq <= k) {
        cout << "YES" << endl;
    } else {
        cout << "MAYBE" << endl;
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
