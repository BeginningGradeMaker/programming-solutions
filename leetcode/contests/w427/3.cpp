typedef long long ll;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(n);
        ll sum = accumulate(nums.begin(), nums.begin() + k, 0ll);
        dp[k-1] = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            if (dp[i - k] >= 0) {
                dp[i] = dp[i - k];
            }
            dp[i] += sum;
        }

        return *max_element(dp.begin() + k - 1, dp.end());
    }
};
