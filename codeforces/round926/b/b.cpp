#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    // 1 * *
    // 1 * *
    // 1 * *
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
      int n, k;
      cin >> n >> k;
      cout << (k <= 4 * n - 4 ? (k + 1) / 2 : 2 * n - 2 + k % (4 * n - 4)) << endl;
    }
}
