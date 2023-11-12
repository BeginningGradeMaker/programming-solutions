#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1;
    int i = 0;
    set<int> st;
    for (int j = 0; j < n; j++) {
        while (!st.empty() && st.count(arr[j])) {
            st.erase(arr[i++]);
        }

        st.insert(arr[j]);
        ans = max(ans, (int) st.size());
    }

    cout << ans << endl;
}
