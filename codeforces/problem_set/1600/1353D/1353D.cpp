#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    auto cmp = [&] (pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }

        return p1.first < p2.first;
    };
    set<pair<int, int>, decltype(cmp)> s(cmp);

    s.insert({n, 0});
    vector<int> ans(n);
    /*cout << "mids: ";*/
    for (int i = 1; i <= n; i++) {
        auto p = *s.rbegin();
        int mid = (p.first - 1) / 2 + p.second;
        /*cout << mid << ' ';*/
        ans[mid] = i;
        s.erase(prev(s.end()));
        s.insert({(p.first - 1) / 2, p.second});
        s.insert({p.first / 2, mid + 1});
    }
    /*cout << endl;*/

    for (int x : ans) {
        cout << x << ' ';
    }
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
