class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] & nums[i]) == nums[j]) {
                    break;
                }
                nums[j] = nums[j] & nums[i];
            }
            /*for (int idx = 0 ; idx <= i; idx++) {*/
            /*    cout << nums[idx] << ' ';*/
            /*}*/
            cout << endl;
            int left = lower_bound(nums.begin(), nums.begin() + i + 1, k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.begin() + i + 1, k) - nums.begin();
            ans += right - left;
        }

        return ans;
    }
};
