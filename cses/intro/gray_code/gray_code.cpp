#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// leetcode 89
int main() {
    // solution goes here
    int n;
    cin >> n;

    vector<string> ans = {"0", "1"};

    for (int i = 2; i < (1<<n); i = i<<1) {

        for (int j = i - 1; j >= 0; j--) {
            ans.push_back(ans[j]);
        }

        for (int j = 0; j < i; j++) {
            ans[j] = "0" + ans[j];
        }

        for (int j = i; j < 2 * i; j++) {
            ans[j] = "1" + ans[j];
        }
    }

    for (auto s : ans) {
        cout << s << endl;
    }
}
