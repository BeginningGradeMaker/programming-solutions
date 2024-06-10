#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(b.begin(), b.end(), greater<int>());

    vector<int> c;

    // We want to add each b_i one by one such that
    // adding it does not increase the length of 
    // the longest increasing subsequence.
    // This can be done by adding b_i before the first
    // j such that b_i >= a_j.
    // Why? If b_i >= a_j, then any subsequence that
    // includes a_j cannot include b_i. Conversely,
    // if a subsequence include b_i, b_i has to be
    // the first element so we can replace b_i with
    // a_j. So a subsequence cannot include both b_i
    // and a_j but can replace each other in a subsequence.
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c.push_back(b[j++]);
        } else {
            c.push_back(a[i++]);
        }
    }

    if (i < n) {
        while (i < n) {
            c.push_back(a[i]);
            i++;
        }
    }
    if (j < m) {
        while (j < m) {
            c.push_back(b[j]);
            j++;
        }
    }

    for (int x : c) cout << x << ' ';
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
