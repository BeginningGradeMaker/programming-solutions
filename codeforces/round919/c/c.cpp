#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

vector<int> factors(int num) {
  vector<int> ans;
  for (int i = 1; i <= num; i++) {
    if (num % i == 0) {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  // solution goes here
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> d = factors(n);
    int cnt = 0;
    for (int k : d) {
      int gd = 0;
      for (int j = 0; j < n - k; j++) {
        gd = __gcd(gd, abs(a[j] - a[j+k]));
      }
      cnt += (gd != 1);
    }
    cout << cnt << endl;
  }
}
