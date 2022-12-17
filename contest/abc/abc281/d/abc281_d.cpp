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
#include <set>
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

void print_vecll(vecll v) {
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

char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

int alphabet_to_int(char s) {
    return s - 'a';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N, K, D;
    cin >> N >> K >> D;
    vecll a(N + 1);
    prep(i, N) {
        cin >> a.at(i);
    }

    vector<vector<vecll>> dp(N + 1, vector<vecll>(K + 1, vecll(D, -1)));
    // dp.at(N).at(K).at(0) = -1;
    prep(i, N) {
        prep(j, K) {
            if (j > i) {
                break;
            }

            if (j == 1) {
                // i番目を採用
                dp.at(i).at(j).at(a.at(i) % D) = max(a.at(i), dp.at(i).at(j).at(a.at(i) % D));
                // i番目を採用しない
                rep(k, D) {
                    dp.at(i).at(j).at(k) = max(dp.at(i).at(j).at(k), dp.at(i - 1).at(j).at(k));
                }
                // cout << i << j << endl;

                // rep(k, D) {
                //     cout << dp.at(i).at(j).at(k) << " " << endl;
                // }
                // cout << endl;
                continue;
            }

            rep(k, D) {
                // i番目を採用
                if (dp.at(i - 1).at(j - 1).at(k) != -1) {
                    int kk = (dp.at(i - 1).at(j - 1).at(k) + a.at(i)) % D;
                    dp.at(i).at(j).at(kk) = max(dp.at(i - 1).at(j - 1).at(k) + a.at(i), dp.at(i).at(j).at(kk));
                }
                // i番目を採用しない
                dp.at(i).at(j).at(k) = max(dp.at(i - 1).at(j).at(k), dp.at(i).at(j).at(k));
            }

            // cout << i << j << endl;

            // rep(k, D) {
            //     cout << dp.at(i).at(j).at(k) << " " << endl;
            // }
            // cout << endl;
        }
    }

    cout << dp.at(N).at(K).at(0) << endl;
    // rep(i, D) {
    //     cout << dp.at(N).at(K).at(i) << " ";
    // }
    // ----------------------------------------------------------------
    return 0;
}