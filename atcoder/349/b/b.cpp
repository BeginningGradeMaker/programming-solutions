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
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Input handling goes here
  string s; cin >> s;
  unordered_map<int, int> freq;
  for (char c : s) freq[c]++;
  unordered_map<int, int> cnt;
  for (auto p : freq) {
    cnt[p.second]++;
  }
  
  for (auto p : cnt) {
    if (p.second != 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
