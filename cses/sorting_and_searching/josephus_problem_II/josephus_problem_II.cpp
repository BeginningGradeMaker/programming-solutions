#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;

  ll removed = 0;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    cout << (cur + k + removed) % (n - removed) << endl;
    removed++;
  }
}
