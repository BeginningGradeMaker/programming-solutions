#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // solution goes here
    int n, k; cin >> n >> k;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    
    int cur = 0;
    while (ans.size() > 1) {
        vector<int> tmp;
        int len = ans.size();
        for (int i = 0; i < len; i++) {
            
        }
    }

    cout << ans[0] <<  endl;
}
