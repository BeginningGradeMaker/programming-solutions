#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

void solve() {
  int n; cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int prev = -1;
  for (int i = 0; i < n; i++) {
    int num = arr[i];
    if (num < prev) {
      cout << "No" << endl;
      return;
    }
    deque<int> tmp;
    while (num > 0) {
      tmp.push_front(num % 10);
      num /= 10;
    }
    bool b = false;
    for (int cur : tmp) {
      // cout << cur << ' ';
      if (cur < prev) {
        b = true;
        break;
      }
      prev = cur;
    }
    if (b) {
      prev = arr[i];
    }
  }
  cout << "Yes" << endl;
}

int main() {
  // solution goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
