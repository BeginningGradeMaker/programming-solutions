#include <bits/stdc++.h>
using namespace std;

int main() {
    // solution goes here
    vector<int> nums;
    int n;
    int input;

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> input;
        nums.push_back(input);
    }

    int num = 0;
    for (int i = 1; i <= n; i++) {
        num ^= i;
    }

    for (auto i : nums) {
        num ^= i;
    }

    cout << num;
}