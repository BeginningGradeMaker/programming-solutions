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

  for (char c : s) cnt[c - 'a']++;

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > cnt[ ans ]) {
      ans = i;
    }
  }

  cout << (char)('a' + ans) << endl;
}
