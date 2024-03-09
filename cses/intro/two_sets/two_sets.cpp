#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    int n;

    cin >> n;


    if (n % 2) {
        if (n / 2 % 2) {
            cout << "YES" << '\n';
            cout << (n + 1) / 2 << '\n';
            for (int i = 1; i <= (n + 1) / 2; i++) {
                if (i % 2)
                    cout << i << ' ';
                else
                    cout << n - i + 1 << ' ';
            }
            cout << '\n';
            cout << n / 2 << '\n';
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2)
                    cout << n - i + 1<< ' ';
                else
                    cout << i << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO";
        }
    } else {
        if (n / 2 % 2) {
            cout << "NO";
        } else {
            cout << "YES" << '\n';
            cout << n / 2 << '\n';
            for (int i = 1; i <= n / 4; i++) {
                cout << i << ' ' << n - i + 1 << ' ';
            }
            cout << '\n';
            cout << n / 2 << '\n';
            for (int i = n / 4 + 1; i <= n / 2; i++) {
                cout << i << ' ' << n - i + 1 << ' ';
            }
            cout << '\n';
        }
    }
}
