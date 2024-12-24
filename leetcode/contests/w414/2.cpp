typedef long long ll;
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        ll l = 0;
        ll r = 2 * 1e9;
        ll ans = 0;

        sort(start.begin(), start.end());

        auto check = [&] (ll t) {
            ll n = start.size();
            ll last = start[0];
            for (ll i = 1; i < n; i++) {
                if (last + t > start[i] + d) {
                    return false;
                }
                last = last + t < start[i] ? start[i] : last + t;
            }

            return true;
        };
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
