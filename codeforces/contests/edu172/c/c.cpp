#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    vector<int> arr;

    int sum = 0;
    for (int i = n-1; i > 0; i--) {
        sum += s[i] == '1' ? 1 : -1;
        if (sum > 0) arr.push_back(sum);
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    while (k > 0 && !arr.empty()) {
        ans += 1;
        k -= arr.back();
        arr.pop_back();
        if (k <= 0) {
            break;
        }
    }

    if (k <= 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
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
