#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int m; cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    if (find(b.begin(), b.end(), d[m-1]) == b.end()) {
        cout << "NO" << endl;
        return;
    }

    map<int, int> dm;
    for (int i = 0; i < m; i++) {
        dm[d[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (dm[b[i]] != 0) {
                dm[b[i]]--;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
