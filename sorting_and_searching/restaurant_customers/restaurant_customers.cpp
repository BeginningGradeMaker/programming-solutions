#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);

    for (int i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int ans = 0;
    for (auto p : time) {
        while (!pq.empty() && pq.top() <= p.first) {
            pq.pop();
        }
        pq.push(p.second);
        ans = max(ans, (int) pq.size());
    } 

    cout << ans << endl;
}
