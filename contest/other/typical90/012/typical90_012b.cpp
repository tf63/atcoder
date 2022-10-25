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

vec string_to_vec(string s) {
    vec v(s.size());
    rep(i, (int)s.size()) {
        v.at(i) = s.at(i) - '0';
    }
    return v;
}

bool dfs(vector<vector<bool>>& G, int ra, int ca, int rb, int cb, vector<vector<bool>> visit) {
    if (visit.at(ra).at(ca)) {
        return false;
    }
    visit.at(ra).at(ca) = true;

    if (!G.at(ra).at(ca)) {
        return false;
    }

    if (ra == rb && ca == cb) {
        return true;
    }

    bool goal = false;
    if (ra != 1) {
        goal |= dfs(G, ra - 1, ca, rb, cb, visit);
    }
    if (ra != (int)G.size() - 1) {
        goal |= dfs(G, ra + 1, ca, rb, cb, visit);
    }
    if (ca != 1) {
        goal |= dfs(G, ra, ca - 1, rb, cb, visit);
    }
    if (ca != (int)G.at(0).size() - 1) {
        goal |= dfs(G, ra, ca + 1, rb, cb, visit);
    }

    return goal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int H, W;
    cin >> H >> W;
    int Q;
    cin >> Q;
    int t;
    int r, c;
    int ra, ca, rb, cb;
    vector<vector<bool>> G(H + 1, vector<bool>(W + 1));
    rep(i, Q) {
        cin >> t;

        if (t == 1) {
            cin >> r >> c;

            G.at(r).at(c) = true;
        } else {
            cin >> ra >> ca >> rb >> cb;
            vector<vector<bool>> visit(H + 1, vector<bool>(W + 1));

            if (!(G.at(ra).at(ca) && G.at(rb).at(cb))) {
                cout << "No" << endl;
                continue;
            }

            if (dfs(G, ra, ca, rb, cb, visit)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    // ----------------------------------------------------------------
    return 0;
}