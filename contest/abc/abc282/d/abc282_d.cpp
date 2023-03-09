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
    int N, M;

    cin >> N >> M;
    vector<vec> G(N + 1, vec());
    set<int> nodes;
    int u, v;
    rep(i, M) {
        cin >> u >> v;
        nodes.insert(u);
        nodes.insert(v);
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    vector<pair<vec, vec>> uv;
    vec cls(N + 1);

    while (!nodes.empty()) {
        int node = *nodes.begin();
        uv.push_back(pair<vec, vec>());

        uv.back().first.push_back(node);
        cls.at(node) = 1;
        nodes.erase(node);

        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            node = q.front();
            nodes.erase(node);
            q.pop();
            for (auto g : G.at(node)) {
                if (cls.at(g) == 0) {
                    // 未探索だったら追加
                    if (cls.at(node) == 1) {
                        uv.back().second.push_back(g);
                        cls.at(g) = 2;
                    } else {
                        uv.back().first.push_back(g);
                        cls.at(g) = 1;
                    }
                    q.push(g);
                } else {
                    if (cls.at(node) == cls.at(g)) {
                        // 連結
                        cout << 0 << endl;
                        return 0;
                    } else {
                        // pass
                    }
                }
            }
        }
    }

    ll ans = -M;
    vec its;
    for (auto it : uv) {
        int fn = (int)it.first.size();
        int sn = (int)it.second.size();
        its.push_back(fn + sn);
        ans = fn * sn;
    }

    for (int i = 0; i < (int)its.size(); i++) {
        for (int j = i + 1; j < (int)its.size(); j++) {
            ans += its.at(i) * its.at(j);
        }
    }

    cout << ans << endl;

    // ----------------------------------------------------------------
    return 0;
}