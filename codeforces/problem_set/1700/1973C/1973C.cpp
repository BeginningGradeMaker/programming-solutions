#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

// NOTE: Constructive

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> p(n);
    for (int &x: p) cin >> x;

    // NOTE: Suppose n is at odd index. Then we can add
    // n/2 + 1, n/2 + 2, ... , n to each number at
    // odd index, by adding larger number to smaller
    // p_i, and smaller number to larger p_i.
    // We show that a_i > n for all odd indices. Suppose
    // for contradiction that p_i + q_i <= n, we know that
    // p_i >= i, and q_i = n - (i - 1) => p_i <= i-1, a
    // contradiction.
    // Similarly, we assign 1, ... , n/2 to each number at
    // even index, with the same rule above.
    // We show that a_i <= n for all even indices. Suppose
    // for contradiction that p_i + q_i > n, we know that
    // q_i = n / 2 - i + 1 <= 2 - p_i + 1
    // => p_i + n / 2 - p_i + 1 > n
    // => n / 2 + 1 > n
    // a contradiction.
    bool b = false;
    for (int i = 0; i < n; i++) {
        if (p[i] == n && i % 2 == 0) {
            b = true;
        }
    }

    if (b) reverse(p.begin(), p.end());

    vector<int> ans(n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++) {
        if (i % 2) odd.push_back(i);
        else even.push_back(i);
    }

    sort(odd.begin(), odd.end(), [&] (int i, int j) {
        return p[i] < p[j];
    });
    sort(even.begin(), even.end(), [&] (int i, int j) {
        return p[i] < p[j];
    });

    for (int i = 0; i < n / 2; i++) {
        ans[odd[i]] = n - i;
    }
    for (int i = 0; i < n / 2; i++) {
        ans[even[i]] = n / 2 - i;
    }

    if (b) reverse(ans.begin(), ans.end());

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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
