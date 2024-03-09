#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

vector<int> z_alg(string s) {
    int l, r, n;
    l = r = -1;
    n = s.size();
    vector<int> z(n, 0);

    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        for (int k = z[i]; k < n - i; k++) {
            if (s[i + k] != s[k]) {
                break;
            }
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }

    return z;
}

int main() {
    // solution goes here
    string s; cin >> s;

    auto z = z_alg(s);
    int n = s.size();
    int l = 0;  
    for (int i = 1; i < n; i++) {
        // cout << z[i] << ' ';
        l = max(l, min(z[i], n-i-1));
    }
    // cout << endl;
    // cout << l << endl;
    int m = 0;
    for (int i = n-1; i >= 1; i--) {
        if (z[i] == n-i && z[i] <= l) {
            m = z[i];
        }
    }
    if (m == 0) {
        cout << "Just a legend" << endl;
    } else {
        cout << s.substr(0, m) << endl;
    }
}
