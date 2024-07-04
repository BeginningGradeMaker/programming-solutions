#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ind(m);
    for (int &x : ind) cin >> x;
    string c; cin >> c;

    multiset<int> S;
    for (int i = 0; i < m; i++) {
        S.insert(c[i]);
    }

    vector<bool> changed(n);

    sort(ind.begin(), ind.end());
    for (int i : ind) {
        i--;
        if (!changed[i]) {
            changed[i] = true;
            s[i] = *S.begin();
            S.erase(S.begin());
        } else {
            if (s[i] <= *S.begin()) {
                S.erase(--S.end());
            } else {
                s[i] = *S.begin();
                S.erase(S.begin());
            }
        }
    }

    cout << s << endl;
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
