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

bool solve(vec& Ax, int& x, int& S, int k, int a) {
    rep(i, Ax[k] + 1) {
        solve(Ax, x, S, k + 1, a + i * k);
    }

    if (k == 10) {
        if (a - (S - a) == x) {
            return true;
        } else {
            return false;
        }
    }

    // rep(i1, Ax[1] + 1) {
    //     rep(i2, Ax[2] + 1) {
    //         rep(i3, Ax[3] + 1) {
    //             rep(i4, Ax[4] + 1) {
    //                 rep(i5, Ax[5] + 1) {
    //                     rep(i6, Ax[6] + 1) {
    //                         rep(i7, Ax[7] + 1) {
    //                             rep(i8, Ax[8] + 1) {
    //                                 rep(i9, Ax[9] + 1) {
    //                                     rep(i10, Ax[10] + 1) {
    //                                         int a = i1 * 1 + i2 * 2 + i3 * 3 + i4 * 4 + i5 * 5 + i6 * 6 + i7 * 7 +
    //                                                 i8 * 8 + i9 * 9 + i10 * 10;
    //                                         if (a - (S - a) == x) {
    //                                             return true;
    //                                         }
    //                                     }
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N, x, y;
    cin >> N >> x >> y;
    vec Ax(11);
    vec Ay(11);
    int a = 0;
    int Sx = 0;
    int Sy = 0;

    int first;
    cin >> first;
    x -= first;

    rep(i, N - 1) {
        cin >> a;
        if (i % 2 == 1) {
            Ax.at(a)++;
            Sx += a;
        } else {
            Ay.at(a)++;
            Sy += a;
        }
    }

    if (solve(Ax, x, Sx, 1, 0) && solve(Ay, y, Sy, 1, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}