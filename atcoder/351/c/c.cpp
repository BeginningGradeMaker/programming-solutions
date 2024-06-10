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
  int n; cin >> n;
  vector<int> a(n);
  vector<int> seq;
  for (int &x : a) cin >> x;

  for (int c : a) {
    seq.push_back(c);
    while (true) {
      if (seq.size() <= 1 || seq.back() != seq[seq.size() - 2]) {
        break;
      }

      int x = seq.back();
      seq.pop_back(); seq.pop_back();
      seq.push_back(x+1);
    }
  }

  cout << seq.size() << endl;
}
