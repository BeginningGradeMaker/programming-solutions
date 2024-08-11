#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 1e9;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> x(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> w[i];
    }
    vector<pair<int, int>> interval(n);
    for (int i = 0; i < n; i++) {
        interval[i] = make_pair(x[i] - w[i], x[i] + w[i]);
    }
    sort(interval.begin(), interval.end(), [] (pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    /*for (int i = 0; i < n; i++) {*/
    /*    cout << "(" << interval[i].first << ", " << interval[i].second << "), ";*/
    /*}*/
    /*cout << endl;*/

    int cnt = 1;
    int f = interval[0].second;
    for (int i = 1; i < n; i++) {
        if (interval[i].first >= f) {
            cnt++;
            f = interval[i].second;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
