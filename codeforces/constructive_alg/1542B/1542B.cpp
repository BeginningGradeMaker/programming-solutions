#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

bool isPower(int x, long int y)
{
    // The only power of 1 is 1 itself
    if (x == 1)
        return (y == 1);
 
    // Repeatedly compute power of x
    long int pow = 1;
    while (pow < y)
        pow *= x;
 
    // Check if power of x becomes y
    return (pow == y);
}

int main() {
    // solution goes here
    int t; cin >> t;
    int n, a, b;

    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        if (isPower(a, n % b)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
