#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll ans = LONG_MIN;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ans = max(ans, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << ans << endl;
}
