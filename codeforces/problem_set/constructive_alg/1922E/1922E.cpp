#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

vector<ll> f(ll x) {
  if (x == 2) {
    return {0};
  } else if (x & 1) {
    vector<ll> arr = f(x-1);
    arr.push_back(*min_element(arr.begin(), arr.end()) - 1);
    return arr;
  } else {
    vector<ll> arr = f(x / 2);
    arr.push_back(*max_element(arr.begin(), arr.end()) + 1);
    return arr;
  }
}

int main() {
    // solution goes here
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
      ll x; cin >> x;
      vector<ll> ans = f(x);
      cout << ans.size() << endl;
      for (ll num : ans) {
        cout << num << ' ';
      }
      cout << endl;
    }
}
