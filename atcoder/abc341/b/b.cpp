#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n-1; i++) {
    ll s, t;
    cin >> s >> t;
    a[i+1] += a[i] / s * t;
  }
  
  cout << a[n-1] << endl;
}
