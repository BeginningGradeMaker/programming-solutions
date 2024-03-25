#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n - 1; i++) {
        if ((s[i] == 'a' && s[i+1] == 'b') || (s[i] == 'b' && s[i+1] == 'a')) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
