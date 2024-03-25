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
  int b = true;

  string s; cin >> s;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '|') {
      b = !b;
    } else {
      if (b) ans.push_back(s[i]);
    }
  }

  cout << ans << endl;
}
