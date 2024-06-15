typedef long long ll;
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // int i = 0;
        // while (i < factory.size()) {
        //     if (factory[i][1] == 0) {
        //         factory.erase(factory.begin() + i);
        //     } else {
        //         i++;
        //     }
        // }
        ll n = robot.size();
        ll m = factory.size();
        vector<vector<ll>> dp(m, vector<ll>(n, 1e9 * n));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [] (vector<int> v1, vector<int> v2) {
            return v1[0] < v2[0];
        });
        if (factory[0][1] > 0) dp[0][0] = abs(factory[0][0] - robot[0]);
        for (ll i = 1; i < min(n, (ll)factory[0][1]); i++) {
            dp[0][i] = dp[0][i-1] + abs(factory[0][0] - robot[i]);
        }

        for (ll i = 1; i < m; i++) {
            for (ll j = 0; j < n; j++) {
                ll sum = 0;
                dp[i][j] = dp[i-1][j];
                for (ll k = j; k >= max(0ll, j - (ll)factory[i][1] + 1ll); k--) {
                    sum += abs(factory[i][0] - robot[k]);
                    dp[i][j] = min(dp[i][j], (k > 0 ? dp[i-1][k-1] : 0) + sum);
                }
            }
        }

        return dp[m-1][n-1];
    }
};
