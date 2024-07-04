#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    string s; cin >> s;

    auto check = [] (vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if (nums[0] == 0) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                return 0;
            }
            dp[i] = nums[i] + dp[i-1];
            int p = 1;
            for (int j = i; j >= 0; j--) {
                p *= nums[j];
                if (p > 180) break;
                dp[i] = min(dp[i], p + (j > 0 ? dp[j-1] : 0));
            }
        }

        return dp[n-1];
    };

    vector<int> nums(n-1);
    nums[0] = stoi(s.substr(0, 2));
    for (int i = 1; i < n-1; i++) {
        nums[i] = s[i+1] - '0';
    }
    int ans = check(nums);

    /*cout << "nums: ";*/
    /*for (int x : nums) {*/
    /*    cout << x << ' ';*/
    /*}*/
    /*cout << endl;*/
    for (int i = 1; i < n-1; i++) {
        nums[i] += 10 * (nums[i-1] % 10);
        nums[i-1] /= 10;
        /*cout << "nums: ";*/
        /*for (int x : nums) {*/
        /*    cout << x << ' ';*/
        /*}*/
        /*cout << endl;*/
        ans = min(ans, check(nums));
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
