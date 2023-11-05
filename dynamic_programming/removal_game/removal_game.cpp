#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;
vector<ll> prefix;

ll SecondPlay(int left, int right, vector<int> &nums);

ll FirstPlay(int left, int right, vector<int> &nums) {
    int n = right - left + 1;

    if (n == 1) return nums[left];

    ll first = SecondPlay(left + 1, right, nums);
    ll last = SecondPlay(left, right - 1, nums);
    if (first > last) {
        return (prefix[right - 1] - (left == 0 ? 0 : prefix[left - 1])) - last + nums[right];
    } else {
        return (prefix[right] - prefix[left]) - first + nums[left];
    }
}

ll SecondPlay(int left, int right, vector<int> &nums) {
    int n = right - left + 1;

    if (n == 1) return nums[left];

    ll first = FirstPlay(left + 1, right, nums);
    ll last = FirstPlay(left, right - 1, nums);
    if (first > last) {
        return (prefix[right - 1] - (left == 0 ? 0 : prefix[left - 1])) - last + nums[right];
    } else {
        return (prefix[right] - prefix[left]) - first + nums[left];
    }
}

int main() {
    // solution goes here
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    prefix = vector<ll>(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    
    cout << FirstPlay(0, n - 1, nums) << endl;
}
