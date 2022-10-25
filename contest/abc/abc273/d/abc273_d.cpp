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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    ll H, W;
    ll r, c;
    cin >> H >> W >> r >> c;
    int N;
    cin >> N;
    vector<vec> wR(H + 1, vec());
    vector<vec> wC(W + 1, vec());
    int wr, wc;
    rep(i, N) {
        cin >> wr >> wc;
        wR.at(wr).push_back(wc);
        wC.at(wc).push_back(wr);
    }
    prep(i, H) {
        if (!wR.at(i).empty()) {
            sort(all(wR.at(i)));
        }
    }
    prep(i, W) {
        if (!wC.at(i).empty()) {
            sort(all(wC.at(i)));
        }
    }

    int Q;
    cin >> Q;
    char d;
    ll l;
    vector<int>::iterator bd;
    rep(i, Q) {
        cin >> d >> l;
        switch (d) {
            case 'L':
                if (wR.at(r).empty()) {
                    c = max(c - l, 1ll);
                } else {
                    bd = lower_bound(all(wR.at(r)), c);
                    if (bd == wR.at(r).begin()) {
                        c = max(c - l, 1ll);
                    } else {
                        c = max(c - l, (ll)(*(bd - 1) + 1));
                    }
                }
                break;

            case 'R':
                if (wR.at(r).empty()) {
                    c = min(c + l, W);
                } else {
                    bd = lower_bound(all(wR.at(r)), c);
                    if (bd == wR.at(r).end()) {
                        c = min(c + l, W);
                    } else {
                        c = min(c + l, (ll)(*bd - 1));
                    }
                }
                break;

            case 'U':
                if (wC.at(c).empty()) {
                    r = max(r - l, 1ll);
                } else {
                    bd = lower_bound(all(wC.at(c)), r);
                    if (bd == wC.at(c).begin()) {
                        r = max(r - l, 1ll);
                    } else {
                        r = max(r - l, (ll)(*(bd - 1) + 1));
                    }
                }
                break;
            case 'D':
                if (wC.at(c).empty()) {
                    r = min(r + l, H);
                } else {
                    bd = lower_bound(all(wC.at(c)), r);
                    if (bd == wC.at(c).end()) {
                        r = min(r + l, H);
                    } else {
                        r = min(r + l, (ll)(*bd - 1));
                    }
                    break;
                }
        }

        cout << r << " " << c << endl;
    }

    // ----------------------------------------------------------------
    return 0;
}