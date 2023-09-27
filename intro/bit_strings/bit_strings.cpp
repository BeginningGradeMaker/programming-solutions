#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll pow(int exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return 2;
    else {
        ll res = pow(exp / 2);

        if (exp % 2 == 0) {
            res = (res * res) % 1000000007;
        } else {
            res = (((res * res) % 1000000007) * 2) % 1000000007;
        }

        return res;
    }
}

int main() {
    // solution goes here
    int n;

    cin >> n;

    cout << pow(n);
}
