class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m = *max_element(nums.begin(), nums.end());
    deque<int> pos;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == m)
        pos.push_back(i);
      if (pos.size() > k)
        pos.pop_front();
      if (pos.size() == k)
        ans += pos[0] + 1;
    }

    return ans;
  }
};
