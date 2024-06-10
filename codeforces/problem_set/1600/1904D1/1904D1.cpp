#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return b[i] < b[j];
    });

    for (int i : idx) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
        bool ok1 = true;
        int idx1 = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (b[j] < b[i] || a[j] > b[i]) {
                ok1 = false;
                break;
            }
            if (a[j] == b[i]) {
                idx1 = j;
                break;
            }
        }

        bool ok2 = true;
        int idx2 = -1;
        for (int j = i + 1; j < n; j++) {
            if (b[j] < b[i] || a[j] > b[i]) {
                ok2 = false;
                break;
            }
            if (a[j] == b[i]) {
                idx2 = j;
                break;
            }
        }
        if ((!ok1 || idx1 == -1) && (!ok2 || idx2 == -1)) {
            cout << "NO" << endl;
            return;
        }

        if (ok1 && idx1 >= 0) {
            for (int j = i; j >= idx1; j--) {
                a[j] = b[i];
            }
        } else if (ok2 && idx2 >= 0){
            for (int j = i; j <= idx2; j++) {
                a[j] = b[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            return;
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
