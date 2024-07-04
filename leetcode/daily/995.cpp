class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> Q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            while (!Q.empty() && i - Q.front() >= k) {
                Q.pop();
            }
            if (nums[i] == 0 && (Q.size() & 1)) {
                return -1;
            } else if (nums[i] == 0 || nums[i] == 1 && Q.size() % 2) {
                if (i + k >= n) return -1;
                cnt++;
                Q.push(i);
            }
        }

        return cnt;
    }
};
