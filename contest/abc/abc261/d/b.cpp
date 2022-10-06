#include <bits/stdc++.h>
#include <stdio.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> X(N);
    rep(i, N) cin >> X[i];

    vector<long long> Y(N + 1, 0);
    rep(i, M) {
        long long c, y;
        cin >> c >> y;
        Y[c] = y;
    }

    vector dp(N + 1, vector<long long>(N + 1, -Inf));
    dp[0][0] = 0;

    rep(i, N) {
        rep(j, N) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + X[i] + Y[j + 1]);
        }
    }

    long long ans = 0;
    rep(i, N + 1) ans = max(ans, dp[N][i]);

    cout << ans << endl;

    return 0;
}
