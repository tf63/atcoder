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

void dfs(int v, Graph& G, vec& visited, int c) {
    visited.at(v) = c;

    for (auto u : G.at(v)) {
        if (visited.at(u) == -1) {
            dfs(u, G, visited, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N, M;
    cin >> N >> M;

    Graph G(2 * N + 1, vec());
    prep(i, N) {
        G.at(i).push_back(N + i);  // R -> B
        G.at(N + i).push_back(i);  // B -> R
    }

    int a, c;
    char b, d;
    prep(i, M) {
        cin >> a >> b >> c >> d;

        if (b == 'B') {
            a += N;
        }

        if (d == 'B') {
            c += N;
        }

        G.at(a).push_back(c);
        G.at(c).push_back(a);
    }

    vec visited(2 * N + 1, -1);
    int color = 0;
    prep(i, 2 * N) {
        if (visited.at(i) == -1) {
            dfs(i, G, visited, color);
            color++;
        }
    }

    vector<bool> count(color, true);

    prep(i, 2 * N) {
        if (G.at(i).size() != 2) {
            count.at(visited.at(i)) = false;
        }
    }

    int ans = 0;
    for (auto cnt : count) {
        if (cnt) {
            ans++;
        }
    }

    cout << ans << " " << color - ans << endl;
    // ----------------------------------------------------------------
    return 0;
}