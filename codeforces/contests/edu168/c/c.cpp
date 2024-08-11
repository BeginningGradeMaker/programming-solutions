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
    stack<int> left;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        /*cout << i << ' ';*/
        if (i & 1) {
            if (s[i] == '(') {
                left.push(i);
            } else {
                ans += i - left.top();
                left.pop();
            }
        } else {
            if (left.empty()) {
                left.push(i);
            } else {
                ans += i - left.top();
                left.pop();
            }
        }
    }
    /*cout << endl;*/
    cout << ans << endl;
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
