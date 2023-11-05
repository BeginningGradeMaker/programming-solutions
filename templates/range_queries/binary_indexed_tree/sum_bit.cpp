#include <bits/stdc++.h>
using namespace std;

class SumBIT {
  public:
    SumBIT(int n): n{n+1}, tree{vector<int>(n+1)} {}

    int sum(int i) {
      i++;
      int ans = 0;
      while (i >= 1) {
        ans += tree[i];
        i -= i & -i;
      }
      return ans;
    }

    void add(int i, int x) {
      i++;
      while (i <= n) {
        tree[i] += x;
        i += i & -i;
      }
    }

    int n;
    vector<int> tree;
};