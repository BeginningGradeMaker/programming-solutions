#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    ll t, y, x;
    cin >> t;
    auto getNum = [] (ll x, ll y) {
        ll group = max(x, y);
        if (group % 2) { // odd
            return group * group - (abs(x - 1) + abs(y - group));
        } else { // even
            return group * group - (abs(x - group) + abs(y - 1));
        }
    };

    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        cout << getNum(x, y) << endl;
    }
}
