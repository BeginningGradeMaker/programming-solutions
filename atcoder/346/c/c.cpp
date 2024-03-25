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
  // Input handling goes here
  ll n, k; cin >> n >> k;
  ll sum = ( k * (k + 1) ) / 2;
  unordered_set<ll> st;

  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    st.insert(x);
  }

  for (ll x : st) {
    if (x <= k) sum -= x;
  }

  cout << sum << endl;
}
