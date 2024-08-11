class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        // dp[i][j] = the number of good integer arrays with arr1[i]
        // at most j and arr2[i] at least nums[i] - j using numbers 
        // up to nums[i]
        // = dp[i-1][]
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(mx+1));
        dp[0][0] = 1;
        for (int x = 1; x <= nums[0]; x++) {
            dp[0][x] = 1;
        }

        for (int i = 1; i < n; i++) {
            int d = max(nums[i] - nums[i-1], 0);
            for (int x = d; x <= nums[i]; x++) {
                // cout << i << ' ' << x << endl;
                dp[i][x] = ((x > 0 ? dp[i][x-1] : 0) + dp[i-1][x-d]) % mod;
            }
        }
        
        long long ans = 0;
        for (long long x : dp[n-1]) {
            ans += x;
            ans %= mod;
        }
        return ans;
    }
};
