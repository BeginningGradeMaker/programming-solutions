#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int n; cin >> n;
  vector<pair<int, int>> arr(n);
  vector<vector<pair<int, int>>> dp;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i].first >> arr[i].seocnd;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
}
