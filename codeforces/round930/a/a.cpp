#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n; cin >> n;
    int b = 0;
    while (n > 0) {n >>= 1; b++;}
    cout << (1 << (b - 1)) << endl;
  }
}
