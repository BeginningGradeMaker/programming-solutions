#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
  // Solution goes here
}

int main() {
  // Input handling goes here
  ll n; cin >> n; vector<ll> A(n);
  for (ll &x : A) {
    cin >> x;
  }
  ll m; cin >> m; vector<ll> B(m);
  for (ll &x : B) {
    cin >> x;
  }
  ll l; cin >> l; vector<ll> C(l); 
  for (ll &x : C) {
    cin >> x;
  }

  unordered_set<int> prod;
  for (int a : A) {
    for (int b : B) {
      for (int c : C) {
        prod.insert(a + b + c);
      }
    }
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    cout << (prod.count(x) ? "Yes" : "No") << endl;
  }
}
