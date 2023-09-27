#include <bits/stdc++.h>
using namespace std;

int main() {
    // solution goes here
    string s;

    cin >> s;

    int m = 1;
    int cur = 1;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cur++;
            m = max(m, cur);
        } else {
            cur = 1;
        }
    }

    cout << m;
}
