#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// math
int main() {
    // solution goes here
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        
        int n = (min(a, b) - (max(a, b) - min(a, b)));
        if (n >= 0 && n % 3 == 0) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl;
        }
    }
}
