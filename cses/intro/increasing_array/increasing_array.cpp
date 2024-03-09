#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    long long n;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < (int) nums.size(); i++) {
        cin >> n;
        nums[i] = n;
    }

    n = 0;
    for (int i = 0; i < (int) nums.size() - 1; i++) {
        if (nums[i + 1] < nums[i]) {
            n += nums[i] - nums[i + 1];
            nums[i + 1] = nums[i];
        }
    }

    cout << n;
}
