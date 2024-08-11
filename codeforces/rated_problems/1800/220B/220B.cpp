#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m; cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> nums;
    for (auto [num, freq] : cnt) {
        if (freq >= num) {
            nums.push_back(num);
        }
    }
    int t = nums.size();
    vector<vector<int>> freq(t, vector<int>(n));
    for (int i = 0; i < t; i++) {
        int num = nums[i];
        if (a[0] == num) {
            freq[i][0] = 1;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < t; j++) {
            int num = nums[j];
            if (a[i] == num) {
                freq[j][i]++;
            }
            freq[j][i] += freq[j][i-1];
        }
    }

    /*for (int num : nums) {*/
    /*    cout << "freq of " << num << ": " << freq[num][n-1] << endl;*/
    /*}*/

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        int ans = 0;
        for (int j = 0; j < t; j++) {
            int num = nums[j];
            if (freq[j][r] - (l > 0 ? freq[j][l-1] : 0) == num) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
