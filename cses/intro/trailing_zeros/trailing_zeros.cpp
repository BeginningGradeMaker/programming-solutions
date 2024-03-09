#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// number theory
int main() {
    // solution goes here
    ll n;

    cin >> n;

    int count = 0;
    int k = 5;

    while (k <= n) {
        count += n / k;
        k *= 5;
    }

    cout << count;
}
