#include <bits/stdc++.h>
using namespace std;

class MaxBIT {
  public:
    MaxBIT(int n): n{n+1}, tree{vector<int>(n+1, INT_MIN)} {}

    int get(int i) {
      i++;
      int ans = 0;
      while (i >= 1) {
        ans = max(ans, tree[i]);
        i -= i & -i;
      }
      return ans;
    }

    void set(int i, int x) {
      i++;
      while (i <= n) {
        tree[i] = max(tree[i], x);
        i += i & -i;
      }
    }

    int n;
    vector<int> tree;
};