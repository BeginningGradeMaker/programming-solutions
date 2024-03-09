#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n + 1; i++) {
    cout << (i & 1 ? '0' : '1');
  }
  cout << endl;
}
