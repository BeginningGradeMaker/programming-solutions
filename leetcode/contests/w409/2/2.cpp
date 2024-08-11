class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q);
        vector<vector<int>> dp1(n, vector<int>(n, 0)));
        vector<vector<int>> dp2(n, vector<int>(n, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp1[i][j] = j - i;
            }
        }

        /*for (int i = 0; i < n; i++) {*/
        /*    for (int j = i; j < n; j++) {*/
        /*        cout << dp[0][i][j] << ' ';*/
        /*    }*/
        /*    cout << endl;*/
        /*}*/

        for (int t = 0; t < q; t++) {
            auto qr = queries[t];
            int l = qr[0], r = qr[1];
            dp2 = dp1;
            for (int i = 0; i <= l; i++) {
                for (int j = r; j < n; j++) {
                    dp2[i][j] = min(dp1[i][j], dp1[i][l] + 1 + dp1[r][j]);
                }
            }
            /*for (int i = 0; i < n; i++) {*/
            /*    for (int j = i; j < n; j++) {*/
            /*        cout << dp[t+1][i][j] << ' ';*/
            /*    }*/
            /*    cout << endl;*/
            /*}*/

            ans[t] = dp2[0][n-1];
            dp1 = dp2;
        }

        return ans;
    }
};
