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
  vector<int> ans;

  int x;
  do {
    cin >> x;
    ans.push_back(x);
  } while (x != 0);

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
