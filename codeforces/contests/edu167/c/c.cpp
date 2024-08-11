#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    int ca = 0;
    int cb = 0;
    int neg = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] != 1) {
            ca++;
        } else if (b[i] == 1 && a[i] != 1) {
            cb++;
        } else if (a[i] == 1 && b[i] == 1) {
            pos++;
        } else if (a[i] == -1 && b[i] == -1){
            neg++;
        }
    }
    while (neg-- > 0) {
        if (ca >= cb) ca--;
        else cb--;
    }
    while (pos-- > 0) {
        if (ca <= cb) ca++;
        else cb++;
    }

    cout << min(ca, cb) << endl;
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
