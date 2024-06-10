#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

// NOTE: Constructive

void solve() {
    // Solution goes here
    int n, k, m; cin >> n >> k >> m;

    string s;
    cin >> s;

    string t;
    int j = 0;
    bool ok = true; // Indicates whether m has counter case
    for (int i = 0; i < n; i++) {
        int cnt = 0; // Number of distinct letters so far
        vector<int> occ(k);
        // Find the letter whose first index is highest
        while (cnt < k && j < m) {
            cnt += !occ[s[j] - 'a'];
            occ[s[j] - 'a'] = 1;
            j++;
        }

        if (cnt < k) {
            // Some letter is missing
            ok = false;
            for (int x = 0; x < k; x++) {
                if (!occ[x]) {
                    t += 'a' + x;
                    break;
                }
            }
        } else {
            t += s[j-1];
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << t << endl;
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
