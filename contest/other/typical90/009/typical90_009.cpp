#pragma GCC optimize("Ofast")
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
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

double modd(double a, double b) {
    if (a >= 0) {
        return a - (int)(a / b) * b;
    } else {
        return a - (int)(a / b - 1) * b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // ----------------------------------------------------------------
    int N;
    cin >> N;
    vector<pair<int, int>> X(N);
    rep(i, N) {
        cin >> X.at(i).first >> X.at(i).second;
    }
    vector<double> angles(N);
    double angle_max = -1;

    rep(i, N) {
        rep(j, N) {
            if (i == j) {
                angles.at(j) = -361;
            } else {
                angles.at(j) = atan2(X.at(j).second - X.at(i).second, X.at(j).first - X.at(i).first) * 180.0 / M_PI;
                if (angles.at(j) < 0) {
                    angles.at(j) += 360;
                }
            }
        }

        double angle_b = angles.at(i);
        double angle_a = angle_b;
        double angle_c = angle_b;
        double angle_cf = angle_b;
        double angle_cs = angle_b;
        sort(all(angles));

        rep(j, N) {
            if (angles.at(j) < 0) {
                continue;
            }
            angle_a = angles.at(j);
            double angle_ideal = modd(angle_a + 180.0, 360.0);
            auto angle_itr = lower_bound(all(angles), angle_ideal);

            if (angle_itr == angles.begin() || angle_itr == angles.begin() + 1) {
                angle_cf = *(angle_itr);
                angle_cs = *(angle_itr + 1);
            } else if (angle_itr == angles.end()) {
                angle_cf = *(angle_itr - 1);
                angle_cs = *(angle_itr - 2);
            } else {
                angle_cf = *(angle_itr);
                angle_cs = *(angle_itr - 1);
            }

            if (abs(angle_cf - angle_a) >= abs(angle_cs - angle_a)) {
                angle_c = angle_cf;
            } else {
                angle_c = angle_cs;
            }
        }
        double angle_permax = min(abs(angle_a - angle_c), 360.0 - abs(angle_a - angle_c));
        angle_max = max(angle_max, angle_permax);
    }

    cout << std::setprecision(10) << angle_max << endl;
    // ----------------------------------------------------------------
    return 0;
}