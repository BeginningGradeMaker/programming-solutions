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
  string s; cin >> s;
  vector<int> cnt(26);
  int n = s.size();

  for (int i = 0; i < n; i++) {
    bool b = true;
    for (int j = 0; j < n; j++) {
      if (j != i && s[i] == s[j]) b = false;
    }
    if (b) cout << i + 1 << endl;
  }
}
