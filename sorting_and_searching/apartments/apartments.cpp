#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> app(n);
    vector<int> apr(m);
    for (int i = 0; i < n; i++) {
        cin >> app[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apr[i];
    }

    sort(app.begin(), app.end());
    sort(apr.begin(), apr.end());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (app[i] - k > apr[j]) j++;
        else if (app[i] + k < apr[j]) i++;
        else { ans++; i++; j++; }
    }

    cout << ans << endl;
}
