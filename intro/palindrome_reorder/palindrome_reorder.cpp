#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[26];

// Hash Table
int main() {
    // solution goes here
    string str;

    cin >> str;

    for (auto c : str) {
        freq[c - 'A']++;
    }

    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            if (odd != -1) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd = i + 'A';
        }
    }

    string ans = str;
    int left = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            while (freq[i] > 1) {
                ans[left] = (char) (i + 'A');
                ans[str.length() - left - 1] = (char) (i + 'A');
                freq[i] -= 2;
                left ++;
            }
            ans[str.length() / 2] = (char) odd;
        } else {
            while (freq[i] > 0) {
                ans[left] = (char) (i + 'A');
                ans[str.length() - left - 1] = (char) (i + 'A');
                freq[i] -= 2;
                left ++;
            }
        }
    }

    cout << ans;
}
