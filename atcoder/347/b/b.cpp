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
  unordered_set<string> st;
  for (int i = 0; i < s.size(); i++) {
    string tmp = "";
    for (int j = i; j < s.size(); j++) {
      tmp += s[j];
      st.insert(tmp);
    }
  }

  cout << st.size() << endl;
}
