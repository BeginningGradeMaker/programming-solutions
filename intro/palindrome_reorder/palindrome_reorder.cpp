#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    string str;
    int freq[26];

    cin >> str;

    for (auto c : str) {
        freq[c - 'A']++;
    }

    int old = 0;
}
