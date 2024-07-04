class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        if (m > n) return 0;
        sort(position.begin(), position.end());
        int l = 0;
        int r = position[n-1] - position[0] + 1;

        auto check = [&] (int d) {
            int cnt = m - 1;
            int i = 1;
            int prev = position[0];
            while (i < n && cnt > 0) {
                if (position[i] - prev >= d) {
                    cnt--;
                    prev = position[i];
                }
                i++;
            }

            return cnt == 0;
        };

        int ans = 0;
        while (l < r) {
            int mid = (l + r) / 2;
            cout << mid << endl;

            if (check(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid;
            }
        }

        return ans;
    }
};
