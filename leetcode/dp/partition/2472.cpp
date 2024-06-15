class Solution {
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    
    vector<int> manacher(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        return vector<int>(begin(res), end(res) - 1);
    }
public:
    int maxPalindromes(string s, int k) {
        // babc
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = k == 1 ? 1 : 0;
        vector<int> mp = manacher(s);

        // if i even -> mp[i]: the longest palidrome centered at i / 2
        // if i odd -> mp[i]: the longest palidrome centered at (i-1) / 2
        // abc
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1];
            for (int j = 0; j <= i - k + 1; j++) {
                int m = (i + j + 1) / 2;
                int len = i - j + 1;
                if (i == n - 1 && j == 5) {
                    cout << m << ' ' << (mp[2 * m] - 1) << ' ' << (mp[2 * m + 1] - 1) << endl;
                }
                if ((len % 2 == 0 && ((mp[2 * m] - 1) >= (i - j + 1))) || 
                    (len % 2 == 1 && ((mp[2 * m + 1] - 1) >= (i - j + 1)))) {
                    dp[i] = max(dp[i], (j > 0 ? dp[j-1] : 0) + 1);
                } else {
                    dp[i] = max(dp[i], (j > 0 ? dp[j-1] : 0));
                }
            }
        }

        return dp[n-1];
    }
};
