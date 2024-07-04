class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;
        sort(nums.begin(), nums.end());

        int mn1 = min(nums[n-1] - nums[3], nums[n-4] - nums[0]);
        int mn2 = min(nums[n-2] - nums[2], nums[n-3] - nums[1]);

        return min(mn1, mn2);
    }
};
