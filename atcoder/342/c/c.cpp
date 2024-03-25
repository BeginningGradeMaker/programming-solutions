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
  int n; cin >> n;
  string s; cin >> s;
  int q; cin >> q;
  vector<pair<char, char>> ops(q);
  for (int i = 0; i < q; i++) {
    cin >> ops[i].first >> ops[i].second;
  }

  vector<char> map(26);
  for (int i = 0; i < 26; i++) {
    map[i] = 'a' + i;
    for (auto [x, y] : ops) {
      if (x == map[i]) {
        map[i] = y; 
      }
    }
  }


  for (char &c : s) {
    c = map[c - 'a'];
  }

  cout << s << endl;
}
