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

void print_vec(vector<pair<int, int>> v) {
    rep(i, (int)v.size()) {
        cout << v.at(i).first << " " << v.at(i).second << ", ";
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

bool pair_eq(pair<int, int> p1, pair<int, int> p2, pair<int, int> q1, pair<int, int> q2) {
    int pl = min(abs(p1.first - p2.first), abs(p1.second - p2.second));
    int pg = max(abs(p1.first - p2.first), abs(p1.second - p2.second));
    int ql = min(abs(q1.first - q2.first), abs(q1.second - q2.second));
    int qg = max(abs(q1.first - q2.first), abs(q1.second - q2.second));

    return pl == ql && pg == qg;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    vector<pair<int, int>> G(0);
    string s;
    rep(i, 9) {
        cin >> s;
        rep(j, 9) {
            if (s.at(j) == '#') {
                pair<int, int> p = make_pair(i, j);
                G.push_back(p);
            }
        }
    }

    vector<pair<int, int>> sq(4);
    int N = (int)G.size();

    if (N < 4) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        sq.at(0) = G.at(i);
        for (int j = i + 1; j < N; j++) {
            sq.at(1) = G.at(j);
            for (int k = j + 1; k < N; k++) {
                sq.at(2) = G.at(k);
                for (int l = k + 1; l < N; l++) {
                    sq.at(3) = G.at(l);

                    sort(all(sq));

                    bool iseq = abs(sq.at(1).first - sq.at(0).first) == abs(sq.at(3).first - sq.at(2).first) &&
                                abs(sq.at(1).second - sq.at(0).second) == abs(sq.at(3).second - sq.at(2).second);

                    iseq &= abs(sq.at(2).first - sq.at(0).first) == abs(sq.at(3).first - sq.at(1).first) &&
                            abs(sq.at(2).second - sq.at(0).second) == abs(sq.at(3).second - sq.at(1).second);

                    iseq &= abs(sq.at(2).first - sq.at(0).first) == abs(sq.at(1).second - sq.at(0).second) &&
                            abs(sq.at(2).second - sq.at(0).second) == abs(sq.at(1).first - sq.at(0).first);

                    if (!iseq) {
                        continue;
                    }

                    int vecmul = (sq.at(1).first - sq.at(0).first) * (sq.at(2).first - sq.at(0).first);
                    vecmul += (sq.at(1).second - sq.at(0).second) * (sq.at(2).second - sq.at(0).second);

                    if (vecmul == 0) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;
    // ----------------------------------------------------------------
    return 0;
}