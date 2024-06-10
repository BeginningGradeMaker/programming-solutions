#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
    // Solution goes here
}

struct Trie {
    unordered_map<ll, Trie*> next;
    ll cnt = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    ll N; cin >> N;
    vector<string> S(N);
    for (auto &s : S) cin >> s;

    Trie *root = new Trie;
    for (auto &s : S) {
        Trie *cur = root;
        for (char c : s) {
            if (!cur->next.count(c)) {
                cur->next[c] = new Trie;
            }
            cur = cur->next[c];
            cur->cnt++;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        string s = S[i];
        Trie *cur = root;
        ll p = root->next[s[0]]->cnt;
        cur = cur->next[s[0]];
        for (ll j = 1; j < s.size(); j++) {
            // cout << i << ' ' << j << endl;
            cur = cur->next[s[j]];
            ans += j * (p - cur->cnt);
            p = cur->cnt;
        }
        ans += (cur->cnt - 1) * s.size();
    }

    cout << ans / 2 << endl;
}
