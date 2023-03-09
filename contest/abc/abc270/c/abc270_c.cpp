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
    rep(i, (int)v.size() - 1) {
        cout << v.at(i) << " ";
    }
    cout << v.back() << endl;
}

vec string_to_vec(string s) {
    vec v(s.size());
    rep(i, (int)s.size()) {
        v.at(i) = s.at(i) - '0';
    }
    return v;
}

int Y = 0;
bool stop = false;
void dfs(vector<vector<int>>& G, int v, vector<bool>& visit, vector<int>& route) {
    visit[v] = true;  // v を訪問済にする
    route.push_back(v);

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (visit[next_v])
            continue;  // next_v が探索済だったらスルー

        if (next_v == Y) {
            stop = true;
        }

        dfs(G, next_v, visit, route);  // 再帰的に探索
    }
    if (!stop) {
        route.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N, X;
    cin >> N >> X >> Y;
    int u, v;
    vector<vector<int>> G(N + 1);
    rep(i, N - 1) {
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    vector<bool> visit(N + 1, false);
    vec route(0);
    dfs(G, X, visit, route);

    rep(i, N) {
        if (route.at(i) == Y) {
            break;
        }
        cout << route.at(i) << " ";
    }

    cout << Y << endl;
    // ----------------------------------------------------------------
    return 0;
}