typedef long long ll;
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll pos = 0;
        ll prev = nums[0];
        int n = nums.size();
        ll ans = 0;
        int i;
        for (i = 1; i < n; i++) {
            if (nums[i] > prev || i == n-1) {
                ans += (ll)(prev * (i - pos));
                pos = i;
                prev = nums[i];
            }
        }

        return ans;
    }
};
