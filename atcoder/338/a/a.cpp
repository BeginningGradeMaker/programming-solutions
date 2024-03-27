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
  int n = s.size();

  if (!isupper(s[0])) {
    cout << "No" << endl;
  } else {
    for (int i = 1; i < n; i++) {
      if (!islower(s[i])) {
        cout << "No" << endl;
        return 0;
      }
    }

    cout << "Yes" << endl;
  }
}
