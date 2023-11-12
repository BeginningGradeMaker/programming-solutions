#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // solution goes here
    int n; cin >> n;
    vector<ll> score(n);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = {score[i], 0};
    }

    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            pair<ll, ll> ans1 = {score[i] + dp[i+1][i+l].second, dp[i+1][i+l].first};
            pair<ll, ll> ans2 = {score[i+l] + dp[i][i+l-1].second, dp[i][i+l-1].first};
            dp[i][i+l] = max(ans1, ans2);
        }
    }

    cout << dp[0][n-1].first << endl;
}
