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

bool dfs(vector<vec>& G, int v, pair<int, int>& p, int color, vector<int>& colors) {
    colors.at(v) = color;
    if (color == 1) {
        p.first++;
    } else if (color == -1) {
        p.second++;
    }

    for (auto g : G.at(v)) {
        if (colors.at(g) == color) {
            return false;
        }
        if (colors.at(g) == 0 && !dfs(G, g, p, -color, colors)) {
            return false;
        }
    }

    return true;
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

    vector<bool> visit(N + 1);

    vector<vec> divG;

    prep(i, N) {
        if (!visit.at(i)) {
            divG.push_back(vec());

            queue<int> q;
            q.push(i);
            divG.back().push_back(i);
            visit.at(i) = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto g : G.at(node)) {
                    if (!visit.at(g)) {
                        q.push(g);
                        divG.back().push_back(g);
                        visit.at(g) = true;
                    }
                }
            }
        }
    }

    vector<bool> visit2(N + 1);
    ll ans = N * (N - 1) / 2 - M;
    for (auto it : divG) {
        pair<int, int> p = {0, 0};
        vector<int> colors(N + 1);
        if (!dfs(G, it.front(), p, 1, colors)) {
            cout << 0 << endl;
            return 0;
        }

        ans -= p.first * (p.first - 1) / 2 + p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;
    // ----------------------------------------------------------------
    return 0;
}