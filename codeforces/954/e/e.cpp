#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    map<int, vector<int>> cnt;

    for (int i = 0; i < n; i++) {
        cnt[a[i] % k].push_back(a[i] / k);
    }

    int odd = 0;
    for (auto &pair : cnt) {
        if (pair.second.size() % 2) {
            odd++;
        }
    }

    if (n % 2 && odd != 1 || n % 2 == 0 && odd != 0) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (auto &pair : cnt) {
        vector<int> &nums = pair.second;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        /*cout << pair.first << endl;*/
        /*for (auto x : nums ) {*/
        /*    cout << x << ' ';*/
        /*}*/
        /*cout << endl;*/
        if (nums.size() % 2 == 0) {
            for (int i = 0; i < n-1; i += 2) {
                ans += nums[i+1] - nums[i];
            }
        } else {
            if (n == 1) {
                continue;
            }
            vector<int> dp(n);
            dp[0] = 0;
            dp[1] = nums[1] - nums[0];
            dp[2] = min(nums[2] - nums[1], nums[1] - nums[0]);
            for (int i = 3; i < n; i++) {
                if (i % 2 == 0) {
                    // odd
                    dp[i] = min(dp[i-2] + nums[i] - nums[i-1], min(dp[i-1], dp[i-3] + nums[i] - nums[i-2]));
                } else {
                    dp[i] = dp[i-2] + nums[i] - nums[i-1];
                }
            }
            ans += dp[n-1];
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
