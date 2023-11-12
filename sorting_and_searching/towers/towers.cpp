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

    multiset<int> st;

    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(arr[i]);
        if (it != st.end()) {
            st.erase(it);
        }

        st.insert(arr[i]);
    }

    cout << st.size() << endl;
}
