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

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

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
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> A(H + 2, vector<bool>(W + 2));
    int a;
    prep(i, H) {
        prep(j, W) {
            cin >> a;
            A.at(i).at(j) = (a == 1);
        }
    }
    prep(i, H) {
        A.at(i).at(0) = !A.at(i).at(1);
        A.at(i).at(W + 1) = !A.at(i).at(W);
    }

    prep(j, W) {
        A.at(0).at(j) = !A.at(1).at(j);
        A.at(H + 1).at(j) = !A.at(H).at(j);
    }
    int ans = 0;
    for (int i = 2; i <= H; i++) {
        bool front = false;
        bool back = false;
        prep(j, W) {
            front |= (A.at(i).at(j) ^ A.at(i - 1).at(j)) && (A.at(i).at(j) ^ A.at(i).at(j - 1)) &&
                     (A.at(i).at(j) ^ A.at(i + 1).at(j)) && (A.at(i).at(j) ^ A.at(i).at(j + 1));

            back |= (A.at(i).at(j) ^ A.at(i - 1).at(j)) && (A.at(i).at(j) ^ A.at(i).at(j - 1)) &&
                    (A.at(i).at(j) ^ !A.at(i + 1).at(j)) && (A.at(i).at(j) ^ A.at(i).at(j + 1));
        }

        // 孤立点が存在したら
        if (front && back) {
            cout << -1 << endl;
            return 0;
        }

        if (front && !back) {
            prep(j, W) {
                A.at(i).at(j) = !A.at(i).at(j);
            }
            ans++;
        }
    }

    cout << ans << endl;
    // ----------------------------------------------------------------
    return 0;
}