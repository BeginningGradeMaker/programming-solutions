#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

ll dfs(vector<int> &nums, ll left, ll right) {
    if (nums.size() == 0) {
        return abs(left - right);
    }

    ll tmp = nums.back();
    nums.pop_back();
    ll num1 = dfs(nums, left + tmp, right);
    ll num2 = dfs(nums, left, right + tmp);
    nums.push_back(tmp);

    return min(num1, num2);
}

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << dfs(arr, 0, 0) << endl;
}
