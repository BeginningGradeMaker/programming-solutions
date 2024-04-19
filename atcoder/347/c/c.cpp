#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  // Solution goes here
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Input handling goes here
  ll n, a, b; cin >> n >> a >> b;
  vector<ll> arr(n);

  for (auto &x : arr) cin >> x;
  for (auto &x : arr) x %= (a + b);

  sort(arr.begin(), arr.end());
  for (int i = 0; i < n-1; i++) {
    if (arr[(i + 1)] - arr[i] > b) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if ((a + b - arr[n-1]) + arr[0] > b) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
