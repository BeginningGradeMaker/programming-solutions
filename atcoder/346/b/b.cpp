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
  int w, b; cin >> w >> b;

  string str = "wbwbwwbwbwbw";

  for (int i = 0; i < 400; i++) {
    int nb = 0, nw = 0;
    for (int j = i; j < 400; j++) {
      if (str[j % str.size()] == 'w') {
        nw++;
      } else {
        nb++;
      }

      if (nb == b && nw == w) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
