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
class UnionFind {
   public:
    // 親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    UnionFind(int N) { Parent = vector<int>(N, -1); }

    // Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = root(Parent[A]);
    }

    // 自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];  // 親をとってきたい]
    }

    // AとBをくっ付ける
    bool connect(int A, int B) {
        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            // すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B)) {
            swap(A, B);
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    map<string, int> smap;
    int key = 0;
    rep(i, N) {
        cin >> S.at(i) >> T.at(i);
        if (smap.count(S.at(i)) == 0) {
            smap[S.at(i)] = key;
            key++;
        }
        if (smap.count(T.at(i)) == 0) {
            smap[T.at(i)] = key;
            key++;
        }
    }

    vector<vec> G(key, vec());
    rep(i, N) {
        G.at(smap[S.at(i)]).push_back(smap[T.at(i)]);
        G.at(smap[T.at(i)]).push_back(smap[S.at(i)]);
    }

    UnionFind uni(key);

    bool has_loop = false;
    rep(i, N) {
        int s = smap[S.at(i)];
        int t = smap[T.at(i)];
        if (uni.root(s) == uni.root(t)) {
            has_loop = true;
        }

        if (has_loop) {
            cout << "No" << endl;
            return 0;
        }

        uni.connect(s, t);
    }

    // vector<bool> visit_all(key);
    // rep(i, key) {
    //     if (visit_all.at(i)) {
    //         continue;
    //     }

    //     vector<bool> visit(key);
    //     queue<int> q;
    //     q.push(i);

    //     while (!q.empty()) {
    //         int v = q.front();
    //         if (visit.at(v)) {
    //             // cout << v << endl;
    //             cout << "No" << endl;
    //             return 0;
    //         }
    //         cout << v << endl;
    //         visit.at(v) = true;
    //         visit_all.at(v) = true;
    //         q.pop();

    //         for (auto g : G.at(v)) {
    //             q.push(g);
    //         }
    //     }
    // }

    cout << "Yes" << endl;
    // ----------------------------------------------------------------
    return 0;
}