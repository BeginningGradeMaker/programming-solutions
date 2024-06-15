class Solution {
    vector<int> z_alg(string s) {
        int l, r, n;
        l = r = -1;
        n = s.size();
        vector<int> z(n, 0);

        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(z[i - l], r - i);
            }
            for (int k = z[i]; k < n - i; k++) {
                if (s[i + k] != s[k]) {
                    break;
                }
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i, r = i + z[i];
            }
        }

        return z;
    }

public:
    int deleteString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            vector<int> z = z_alg(s.substr(i));
            for (int j = i + 1; j <= (n - 1 + i) / 2; j++) {
                if (z[j] >= j - i) {
                    dp[i] = max(dp[i], 1 + max(1, dp[j]));
                }
            }
        }

        return dp[0];
    }
};
