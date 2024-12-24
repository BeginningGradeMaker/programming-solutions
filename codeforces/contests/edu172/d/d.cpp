#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<pair<int, int>> seg(n);
    vector<int> cnt(n);
    unordered_map<int, unordered_map<int, int>> S;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
        S[seg[i].first][seg[i].second]++;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    for (int k = 0; k < 2; k++) {
        sort(idx.begin(), idx.end(), [&] (int i, int j) -> bool {
            if (seg[i].first == seg[j].first) {
                return seg[i].second > seg[j].second;
            } else {
                return seg[i].first < seg[j].first;
            }
        });
        set<int> R;
        for (int i : idx) {
            auto it = R.lower_bound(seg[i].second);
            if (it != R.end()) {
                cnt[i] += *it - seg[i].second;
            } 
            R.insert(seg[i].second);
        }

        for (auto &s : seg) {
            s.first = -s.first;
            s.second = -s.second;
            swap(s.first, s.second);
        }
    }

    for (int i = 0; i < n; i++) {
        if (S[seg[i].first][seg[i].second] > 1) {
            cout << 0 << endl;
        } else {
            cout << cnt[i] << endl;
        }
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
