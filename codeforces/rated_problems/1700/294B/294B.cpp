#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> t(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> w[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        if (w[i] == w[j]) return t[i] < t[j];
        return w[i] > w[j];
    });
    int ans = 0;
    int sum = accumulate(w.begin(), w.end(), 0);
    for (int i = 0; i < n; i++) {
        if (ans >= sum) {
            cout << ans << endl;
            return;
        }
        ans += t[idx[i]];
        sum -= w[idx[i]];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
