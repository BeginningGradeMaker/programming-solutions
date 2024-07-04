class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    int i = 0;
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int j = 0; j < nums.size(); j++) {
      cnt[nums[j]]++;
      while (cnt[nums[j]] > k) {
        cnt[nums[i++]]--;
      }
      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
