#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    ll total = accumulate(a.begin(), a.end(), 0ll);

    auto check = [&] (vector<vector<int>> arr) -> vector<int> {
        vector<int> ans;
        ll sum = 0;
        int idx = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[idx][i];
            if (sum >= (total + 2ll) / 3ll) {
                ans.push_back(l+1);
                if (idx == 2) {
                    ans.push_back(n);
                    break;
                } else {
                    ans.push_back(i+1);
                }
                l = i+1;
                idx = idx + 1;
                sum = 0;
            }
        }

        return ans;
    };

    vector<int> res = check({a, b, c});
    if (res.size() == 6) {
        cout << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << ' ' << res[4] << ' ' << res[5];
        cout << endl;
        return;
    }
    res = check({a, c, b});
    if (res.size() == 6) {
        cout << res[0] << ' ' << res[1] << ' ' << res[4] << ' ' << res[5] << ' ' << res[2] << ' ' << res[3];
        cout << endl;
        return;
    }
    res = check({b, a, c});
    if (res.size() == 6) {
        cout << res[2] << ' ' << res[3] << ' ' << res[0] << ' ' << res[1] << ' ' << res[4] << ' ' << res[5];
        cout << endl;
        return;
    }
    res = check({b, c, a});
    if (res.size() == 6) {
        cout << res[4] << ' ' << res[5] << ' ' << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3];
        cout << endl;
        return;
    }
    res = check({c, a, b});
    if (res.size() == 6) {
        cout << res[2] << ' ' << res[3] << ' ' << res[4] << ' ' << res[5] << ' ' << res[0] << ' ' << res[1];
        cout << endl;
        return;
    }
    res = check({c, b, a});
    if (res.size() == 6) {
        cout << res[4] << ' ' << res[5] << ' ' << res[2] << ' ' << res[3] << ' ' << res[0] << ' ' << res[1];
        cout << endl;
        return;
    }

    cout << -1 << endl;
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
