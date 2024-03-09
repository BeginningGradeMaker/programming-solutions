#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    multiset<int> nums;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        nums.insert(k);
    }

    /* We show that for any i = 0...n-1, sum(arr[1...i])+1 cannot be subset sum if and only if sum(arr[1...i])+1 < arr[i] and 
    */
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans+1 < *nums.begin() && !nums.count(ans+1)) {
            cout << ans + 1 << endl;
            return 0;
        }

        ans += *nums.begin();
        nums.erase(nums.begin());
    }

    cout << ans + 1 << endl;
}