#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    string s; cin >> s;
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (isalpha(s[i]) && isdigit(s[i+1])) {
            ok = false;
            break;
        }
    }

    char ld = '0';
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            if (ld > s[i]) {
                ok = false;
                break;
            }
            ld = s[i];
        }
    }

    ld = 'a';
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            if (ld > s[i]) {
                ok = false;
                break;
            }
            ld = s[i];
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
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
