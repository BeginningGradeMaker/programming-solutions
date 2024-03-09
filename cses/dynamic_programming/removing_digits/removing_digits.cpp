#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n;
    cin >> n;
    vector<int> dp(n + 1, n);

    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num > 0) {
            dp[i] = min(dp[i - num % 10] + 1, dp[i]);
            num /= 10;
        }
    }

    cout << dp[n];
}
