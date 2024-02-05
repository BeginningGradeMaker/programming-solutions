#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

/***
* Given a string s of length n, the z-algorithm calculates
* an array z such that z[i] is the length of longest string
* that is both the prefix of s and prefix of suffix of s
* staring at i.
*/

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
