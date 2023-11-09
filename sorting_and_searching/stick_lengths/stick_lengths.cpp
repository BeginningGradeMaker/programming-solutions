#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int md = nums[n/2];

    ll ans = 0;
    for (int num : nums) {
        ans += abs(num - md);
    }

    cout << ans << endl;
}
