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
#define tup pair<int, int>

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

double get_distance(tup a, tup b) {
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double get_cos(tup A, tup B, tup R) {
    double a = get_distance(A, B);
    double b = get_distance(A, R);
    double r = get_distance(B, R);
    double cosval = (a * a + b * b - r * r) / (2 * a * b);
    return cosval;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    pair<double, double> A, B, C, D;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cin >> D.first >> D.second;

    vecd angle(4);
    angle.at(0) = std::acos(get_cos(A, B, D));
    angle.at(1) = std::acos(get_cos(B, A, C));
    angle.at(2) = std::acos(get_cos(C, B, D));
    angle.at(3) = std::acos(get_cos(D, A, C));
    int angle_max_index = max_element(all(angle)) - angle.begin();

    double angle_sum = 0;
    rep(i, 4) {
        if (i != angle_max_index) {
            angle_sum += angle.at(i);
        }
    }

    if (angle_sum > M_PI) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // ----------------------------------------------------------------
    return 0;
}