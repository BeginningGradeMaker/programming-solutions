#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    set<int> st;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        st.insert(k);
    }

    cout << st.size() << endl;
}
