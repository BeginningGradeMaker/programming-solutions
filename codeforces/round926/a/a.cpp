#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int t; cin >> t;
    
    for (int i = 0; i < t; i++) {
        int mi = numeric_limits<int>::max();
        int ma = numeric_limits<int>::min();  
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int k; cin >> k;
            mi = min(mi, k); ma = max(ma, k);
        }
        cout << ma - mi << endl;
    }

}
