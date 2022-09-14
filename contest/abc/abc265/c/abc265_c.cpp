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
// vector<vector<char>> grid(H, vector<char>(W));

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
    cout << i;
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
#define MINF INT_MIN
#define LINF LLONG_MAX
#define MLINF LLONG_MIN

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const unsigned int bit0 = (1 << 0);  // 0000 0000 0000 0001
const unsigned int bit1 = (1 << 1);  // 0000 0000 0000 0010
const unsigned int bit2 = (1 << 2);  // 0000 0000 0000 0100
const unsigned int bit3 = (1 << 3);  // 0000 0000 0000 1000
const unsigned int bit4 = (1 << 4);  // 0000 0000 0001 0000
const unsigned int bit5 = (1 << 5);  // 0000 0000 0010 0000
const unsigned int bit6 = (1 << 6);  // 0000 0000 0100 0000
const unsigned int bit7 = (1 << 7);  // 0000 0000 1000 0000
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H + 1, vector<char>(W + 1));
    vector<vector<bool>> visit(H + 1, vector<bool>(W + 1, false));

    prep(i, H) {
        prep(j, W) {
            cin >> G.at(i).at(j);
        }
    }

    int i = 1;
    int j = 1;
    while (true) {
        visit.at(i).at(j) = true;

        switch (G.at(i).at(j)) {
            case 'U':
                if (i != 1) {
                    i--;
                } else {
                    cout << i << " " << j << endl;
                    return 0;
                }
                break;
            case 'D':
                if (i != H) {
                    i++;
                } else {
                    cout << i << " " << j << endl;
                    return 0;
                }
                break;
            case 'L':
                if (j != 1) {
                    j--;
                } else {
                    cout << i << " " << j << endl;
                    return 0;
                }
                break;
            case 'R':
                if (j != W) {
                    j++;
                } else {
                    cout << i << " " << j << endl;
                    return 0;
                }
                break;
        }
        if (visit.at(i).at(j)) {
            cout << -1 << endl;
            return 0;
        }
    }
    // ----------------------------------------------------------------
    return 0;
}