#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, m; 
    cin >> n >> m;
    vector<int> pos(n+1);
    vector<int> nums(n+1);
    vector<pair<int, int>> op(m);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        pos[k] = i;
        nums[i] = k;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        op[i].first = min(a, b);
        op[i].second = max(a, b);
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i-1]) {
            ans++;
        }
    }

    for (auto pair : op) {
        int a = pair.first, b = pair.second;
        if (a == b) {
            cout << ans << endl;
            continue;
        }

        if (nums[b] == nums[a] + 1) {
            if (nums[a] != 1 && pos[nums[a]-1] <= b && pos[nums[a]-1] > a) {
                ans--;
            }
            if (pos[nums[a]+1] <= b && pos[nums[a]+1] > a) {
                ans++;
            }
            if (nums[b] != n && pos[nums[b]+1] < b && pos[nums[b]+1] >= a) {
                ans--;
            }
        } else if (nums[a] == nums[b] + 1) {
            if (pos[nums[b]-1] < b && pos[nums[b]-1] >= a) {
                ans++;
            }
            if (nums[b] != n && pos[nums[b]+1] < b && pos[nums[b]+1] >= a) {
                ans--;
            }
            if (pos[nums[a]+1] <= b && pos[nums[a]+1] > a) {
                ans++;
            }
        } else {
            if (nums[a] != 1 && pos[nums[a]-1] <= b && pos[nums[a]-1] > a) {
                ans--;
            }
            if (pos[nums[a]+1] <= b && pos[nums[a]+1] > a) {
                ans++;
            }
            if (nums[b] != n && pos[nums[b]+1] < b && pos[nums[b]+1] >= a) {
                ans--;
            }
            if (pos[nums[b]-1] < b && pos[nums[b]-1] >= a) {
                ans++;
            }
        }
        
        swap(pos[nums[a]], pos[nums[b]]);
        swap(nums[a], nums[b]);
        cout << ans << endl;
    }
}
