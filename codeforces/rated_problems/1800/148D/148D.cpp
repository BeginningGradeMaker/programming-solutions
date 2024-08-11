#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int w, b; cin >> w >> b;
    // dp[w][b] = the probability of winning when there
    // are w white mouses and b black mouses.
    vector<vector<double>> dp(w+1, vector<double>(b+1));
    if (w == 0) {
        printf("%.9lf\n",0.0);
        return;
    }
    if (b == 0) {
        printf("%.9lf\n",1.0);
        return;
    }
    dp[0][0] = 0.0;
    for (int i = 1; i <= w; i++) {
        dp[i][0] = 1.0;
        dp[i][1] = i * 1.0 / (i + 1);
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 2; j <= b; j++) {
            double draw_w = i*1.0 / (i + j);
            double draw_b = j*1.0 / (i + j);
            dp[i][j] = draw_w + draw_b * (j-1) / (i+j-1) * (
                i*1.0 / (i+j-2) * dp[i-1][j-2] +
                (j-2)*1.0 / (i+j-2) * (j >= 3 ? dp[i][j-3] : 0.0)
            );
        }
    }

    /*cout << dp[w][b] << endl;*/
    printf("%.9lf\n",dp[w][b]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
