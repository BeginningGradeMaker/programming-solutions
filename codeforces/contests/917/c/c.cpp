#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int t; cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k, d; cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
      cin >> v[i];
    }
  
    // for each i in 0 ... 2n, count the result
    // of waiting for i days
    int ans = 0;
    for (int i = 0; i < d && i < 2 * n; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        cur += a[j] == (j + 1);
      }
      cur += (d - i - 1) / 2; // i+1th day is used to reset
      ans = max(ans, cur);
      for (int j = 0; j < v[i % k]; j++) {
        a[j]++;
      }
    }
    cout << ans << endl;
  }
}
