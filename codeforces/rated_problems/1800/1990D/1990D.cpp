#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> black(n);
    for (int i = 0; i < n; i++) {
        cin >> black[i];
    }

    // dp[i] = the minimum number of operations needed to dye 0 ... ith rows black
    /*vector<int> dp(n);*/
    /*dp[0] = black[0] > 0;*/
    int ans = 0;
    int cnt = 0;
    int f = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (black[i] == 0) {
            f = 0; s = 0;
            continue;
        } else if (black[i] <= 2) {
            if (!f) {
                cnt++;
                f = 1;
            } else {
                f = 0;
            }
            s = 0;
        } else if (black[i] <= 4) {
            if (!f && !s) {
                cnt++;
            } else {
                if (!f) {
                    cnt++;
                    f = 1;
                } else {
                    f = 0;
                }
                if (!s) {
                    cnt++;
                    s = 1;
                } else {
                    s = 0;
                }
            }
        } else {
            f = 0; s = 0;
            cnt++;
        }
    }

    cout << cnt << endl;
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
