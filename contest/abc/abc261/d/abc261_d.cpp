#pragma GCC optimize("Ofast")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
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

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

#define INF INT_MAX
#define MINF INT_MIN
#define LINF LLONG_MAX
#define MLINF LLONG_MIN

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const unsigned int bit0 = (1 << 0);  // 0000 0000 0000 0001
const unsigned int bit1 = (1 << 1);  // 0000 0000 0000 0010
const unsigned int bit2 = (1 << 2);  // 0000 0000 0000 0100
const unsigned int bit3 = (1 << 3);  // 0000 0000 0000 1000
const unsigned int bit4 = (1 << 4);  // 0000 0000 0001 0000
const unsigned int bit5 = (1 << 5);  // 0000 0000 0010 0000
const unsigned int bit6 = (1 << 6);  // 0000 0000 0100 0000
const unsigned int bit7 = (1 << 7);  // 0000 0000 1000 0000
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N, M;
    cin >> N >> M;
    vec X(N);
    rep(i, N) {
        cin >> X.at(i);
    }

    vec Y(N + 1);
    int c, y;
    rep(i, M) {
        cin >> c >> y;
        Y.at(c) = y;
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -LINF));
    dp.at(0).at(0) = 0;

    rep(i, N) {
        rep(j, N) {
            dp.at(i + 1).at(0) = max(dp.at(i + 1).at(0), dp.at(i).at(j));
            dp.at(i + 1).at(j + 1) = max(dp.at(i + 1).at(j + 1), dp.at(i).at(j) + Y.at(j + 1) + X.at(i));
        }
    }

    ll sum = *max_element(all(dp.at(N)));

    cout << sum << endl;
    // ----------------------------------------------------------------
    return 0;
}