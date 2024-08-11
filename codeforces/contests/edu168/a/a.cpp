#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            s.insert(s.begin() + i + 1, (char)('a' + (s[i] - 'a' + 1) % 26));
            cout << s << endl;
            return;
        }
    }
    s.push_back('a' + (s[n-1] - 'a' + 1) % 26);
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
