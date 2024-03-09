#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> arr(n+1);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        arr[k] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] < arr[i-1]) {
            ans++;
        }
    }

    cout << ans << endl;
}
