#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<pair<int, int>> time(n);

    for (int i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end(), [] (pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second < p2.second;
    });

    int last = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (time[i].first >= last) {
            ans++;
            last = time[i].second;
        }
    }

    cout << ans << endl;
}
