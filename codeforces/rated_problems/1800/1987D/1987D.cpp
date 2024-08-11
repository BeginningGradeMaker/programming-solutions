#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    vector<int> c;
    for (auto [_, f] : cnt) {
        c.push_back(f);
    }
    int m = c.size();

    // Note that the optimal strategy for Alice is to always pick the smallest number,
    // once she picked a number, she can't pick its duplicates (if any) again, so Bob
    // won't pick it either, and thus this is equivalent to Alice remove c_i if she picks
    // the ith number. 
    // Bob would want to remove the number before Alice has picked it, then Bob has to
    // remove all the duplicates for that value (or he won't attempt it). Suppose Bob
    // has removed c_i_1, .... , c_i_k, and he wants to remove a number c_j such that
    // j > i_k. Then it's possible if and only if 
    //      j > (k + c_i_1 + ... + c_i_k + c_j) 
    // because Alice would have played c_i_1 + ... + c_i_k turns (removed this many 
    // previous numbers) and Bob has removed k numbers, and he needs c_j turns to 
    // remove c_j before Alice arrives.
    // So the solution is try to expand the set of eliminated numbers by Bob, since
    // Alice has a fixed optimal strategy.
    // Let S_k be the set of indices of numbers of size k removed by Bob, dp[i][j] be the minimum sum
    // of numbers indexed by S_j. We have
    //  dp[i][j] = dp[i-1][j], or
    //           max(dp[i-1][j], dp[i-1][j-1] + c[i]) if (dp[i-1][j-1] + c[i] + j - 1 < i + 1)
    vector<vector<int>> dp(m, vector<int>(m+1, INF));
    // Base case: dp[i][0] = 0 since not choosing any number would result in size of 0 and sum of 0.
    for (int i = 0; i < m; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][j-1] + c[i] <= i - j + 1) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + c[i]);
            }
        }
    }

    int ans = m;
    while (dp[m-1][ans] == INF) {
        ans--;
    }

    cout << (m -  ans) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
