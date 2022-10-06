#pragma GCC optimize("Ofast")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>
#define Graph vector<vector<int>>
#define wGraph vector<vector<Edge>>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
        cout << i;
  }
*/
/* for (auto& x: X) {
        cin >> x;
    }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

#define INF INT_MAX
#define LINF LLONG_MAX

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

/* -------------------------------------------------------------------
if (bit & (1 << i)) -> i番目のフラグがたっているか
bit |= (1 << i) -> i番目のフラグをたてる
bit &= ~(1 << i) -> i番目のフラグを消す
__builtin_popcount(bit) -> 何個のフラグが立っているか

bit |= mask -> maskで表された部分のフラグをまとめて立てる
bit &= ~mask -> maskで表された部分のフラグをまとめて消す
bit & mask -> maskで表された部分の情報のみを取り出したもの
------------------------------------------------------------------- */

vec pow_vec{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

vecll pow_vecll{1,        10,        100,        1000,        10000,        100000,       1000000,
                10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}

vec string_to_vec(string s) {
    vec v(s.size());
    rep(i, (int)s.size()) {
        v.at(i) = s.at(i) - '0';
    }
    return v;
}

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N;
    cin >> N;
    vector<tuple<int, int, int>> T(N + 1);
    int d, c, s;
    T.at(0) = {0, 0, 0};
    prep(i, N) {
        cin >> d >> c >> s;
        T.at(i) = {d, c, s};
    }
    int Dmax = get<0>(*max_element(all(T), compare));
    vector<vecll> dp(N + 1, vecll(Dmax + 1));

    sort(all(T), compare);

    prep(i, N) {
        d = get<0>(T.at(i));
        c = get<1>(T.at(i));
        s = get<2>(T.at(i));
        rep(j, Dmax + 1) {
            if (j < c || j > d) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c] + s);
            }
        }
    }

    ll out = 0;
    prep(i, Dmax) {
        out = max(out, dp[N][i]);
    }
    cout << out << endl;

    // ----------------------------------------------------------------
    return 0;
}