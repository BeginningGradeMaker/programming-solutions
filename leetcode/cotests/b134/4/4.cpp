typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k1) {
        ll n = nums.size();

        auto atleast_k = [&] (ll k) -> ll {
            vector<ll> cnt(32);
            ll ans = 0;
            ll i = 0;
            for (ll j = 0; j < n; j++) {
                ll x = nums[j];
                for (ll idx = 0; idx < 32; idx++) {
                    if (x & (1 << idx)) {
                        cnt[idx]++;
                    }
                }
                ll cur = 0;
                for (ll idx = 0; idx < 32; idx++) {
                    if (cnt[idx] == j - i + 1) {
                        cur |= (1 << idx);
                    }
                }

                if (cur >= k) {
                    ans += (j - i + 1);
                    /*cout << "k: " << k << ' ' << i << ' ' << j << endl;*/
                } else {
                    while (i <= j && cur < k) {
                        for (ll idx = 0; idx < 32; idx++) {
                            if (nums[i] & (1 << idx)) {
                                cnt[idx]--;
                            }
                        }
                        cur = 0;
                        i++;
                        for (ll idx = 0; idx < 32; idx++) {
                            if (cnt[idx] == j - i + 1) {
                                cur |= (1 << idx);
                            }
                        }
                    }
                    if (cur >= k) {
                        ans += (j - i + 1);
                        /*cout << "k: " << k << ' ' << i << ' ' << j << endl;*/
                    }
                }
            }

            return ans;
        };

        return atleast_k(k1) - atleast_k(k1+1);
    }
};
