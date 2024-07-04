typedef long long ll;

class Solution {
    ll mod = 1e9 + 7;
    
    long pow(long x, int n) {
        long res = 1L;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
public:
    int countAnagrams(string s) {
        ll n = s.size();

        auto fact = [&] (ll num) -> ll {
            ll ans = 1;
            for (ll i = 2; i <= num; i++) {
                ans *= i;
                ans %= mod;
            }

            return ans;
        };

        ll ans = 1;
        ll tmp = 1;
        ll len = 0;
        ll i = 0;
        while (i < n) {
            unordered_map<char, ll> cnt;
            while (i < n && s[i] != ' ') {
                cnt[s[i++]]++;
                len++;
            }
            for (auto [_, x] : cnt) {
                tmp *= fact(x);
                tmp %= mod;
            }
            ans *= fact(len);
            ans %= mod;
            len = 0;
            i++;
        }

        return ans * pow(tmp, mod - 2) % mod;
    }
};
