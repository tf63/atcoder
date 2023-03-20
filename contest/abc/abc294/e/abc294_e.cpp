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

int mmod(int a, int b) {
    a += (abs(a / b) + 1) * b;
    return a % b;
}

ll mmod(ll a, ll b) {
    a += (abs(a / b) + 1) * b;
    return a % b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    // vector<int> a{1, 4, 5, 10};
    // int x = 3;
    // cout << *lower_bound(all(a), x) << endl;
    // cout << *upper_bound(all(a), x) << endl;
    int L, N1, N2;
    cin >> L >> N1 >> N2;
    vec v1(N1), v2(N2), l1(N1), l2(N2), d1(N1), d2(N2);
    int d = -1;
    rep(i, N1) {
        cin >> v1.at(i) >> l1.at(i);

        d += l1[i];
        d1[i] = d;
    }

    d = -1;
    rep(i, N2) {
        cin >> v2.at(i) >> l2.at(i);

        d += l2[i];
        d2[i] = d;
    }

    ll ans = 0;
    rep(i, N1) {
        int left1, right1, left2, right2;
        if (i == 0) {
            left1 = 0;
            right1 = d1[i];
        } else if (true) {
            left1 = d1[i - 1] + 1;
            right1 = d1[i];
        }

        int jd = lower_bound(all(d2), left1) - d2.begin();
        if (jd == 0) {
            left2 = 0;
            right2 = d2[jd];
        } else {
            left2 = d2[jd - 1] + 1;
            right2 = d2[jd];
        }

        if (v1[i] == v2[jd]) {
            ans += min(right1 - left1, right2 - left1) + 1;
        }

        if (i != N1 - 1) {
            int jd2 = lower_bound(all(d2), right1) - d2.begin();
            if
                if (jd2 == 0) {
                    left2 = 0;
                    right2 = d2[jd2];
                } else {
                    left2 = d2[jd2 - 1] + 1;
                    right2 = d2[jd2];
                }
            if (jd != jd2 && v1[i] == v2[jd2]) {
                ans += right1 - left2;
            }
        }
    }
    cout << ans << endl;
    // ----------------------------------------------------------------
    return 0;
}