#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        if (n <= 3) {
            cout << -1 << endl;
            continue;
        }
        if (n == 4) {
            cout << "2 4 1 3" << endl;
            continue;
        }
        if (n % 3 == 0) {
            cout << 1 << ' ';
            for (int x = 3; x <= n; x += 3) {
                cout << x << ' ';
            }
            for (int x = n - 2; x >= 4; x -= 3) {
                cout << x << ' ';
            }
            cout << 2 << ' ';
            for (int x = 5; x <= n; x += 3) {
                cout << x << ' ';
            }
            cout << endl;
        } else if (n % 3 == 1) {
            int tmp = n - 1;
            cout << 1 << ' ';
            for (int x = 3; x <= tmp; x += 3) {
                cout << x << ' ';
            }
            for (int x = tmp - 2; x >= 4; x -= 3) {
                cout << x << ' ';
                if (x == 4) cout << 2 << ' ';
            }
            for (int x = 5; x <= tmp; x += 3) {
                cout << x << ' ';
            }
            cout << n << ' ';
            cout << endl;
        } else {
            int tmp = n - 2;
            cout << 1 << ' ';
            for (int x = 3; x <= tmp; x += 3) {
                cout << x << ' ';
            }
            cout << n << ' ';
            for (int x = tmp - 2; x >= 4; x -= 3) {
                cout << x << ' ';
            }
            cout << 2 << ' ';
            for (int x = 5; x <= tmp; x += 3) {
                cout << x << ' ';
            }
            cout << n - 1 << ' ';
            cout << endl;
        }
    }
}
