#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void dfs(int from, int middle, int to, int n) {
    if (n == 0) return;

    dfs(from, to, middle, n-1);
    cout << from << ' ' << to << endl;
    dfs(middle, from, to, n-1);
}

int main() {
    // solution goes here
    int n;
    cin >> n;

    cout << (1<<n)-1 << endl;

    dfs(1, 2, 3, n);
}
