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

int next_combination(int sub) {
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int H1, H2, W1, W2;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1)), B(H2, vector<int>(W2));
    // rep(i, H1) {
    //     rep(j, W1) {
    //         cin >> A.at(i).at(j);
    //     }
    // }
    cin >> H2 >> W2;
    // rep(i, H2) {
    //     rep(j, W2) {
    //         cin >> B.at(i).at(j);
    //     }
    // }
    vec hind(H2);
    vec wind(W2);

    int hveci = 0, wveci = 0;

    int hbit = (1 << H2) - 1;
    int wbit = (1 << W2) - 1;

    bool equal = true;
    cout << "a" << endl;
    for(; hbit < (1 << H1); hbit = next_combination(hbit)) {
        
        rep(i, H1) {
            if (hbit & (1 << i)) {
                hind.at(hveci) = i;
                hveci++;
            }
            cout << "b";
        }
        cout << "a1" << endl;
        hveci = 0;
        for(; wbit < (1 << W1); wbit = next_combination(wbit)) {
            
            rep(i, W1) {
                if (wbit & (1 << i)) {
                    wind.at(wveci) = i;
                    wveci++;
                }
                cout << "b";
                wveci = 0;
            }
            cout << hind.at(0) << " " << hind.at(1) << " " << hind.at(2) << " " << wind.at(0) << " " << wind.at(1) << " " << wind.at(2) << endl;
            // rep(i, H2) {
            //     rep(j, W2) {
            //         if (A.at(hind.at(i)).at(wind.at(j)) != B.at(i).at(j)) {
            //             equal = false;
            //         }
            //     }
            // }

            // if (equal) {
            //     cout << "Yes" << endl;
            //     return 0;
            // }
        }
    }

    cout << "No" << endl;
    // ----------------------------------------------------------------
    return 0;
}