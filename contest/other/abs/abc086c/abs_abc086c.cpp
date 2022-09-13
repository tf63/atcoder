#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>

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

#define INF 2000000000
#define MINF -200000000

void print_vec(vec v) {
  rep(i, (int)v.size()) { cout << v.at(i); }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------
  int N;
  cin >> N;
  vec t(N + 1), x(N + 1), y(N + 1);
  t.at(0) = 0;
  x.at(0) = 0;
  y.at(0) = 0;
  rep(i, N) { cin >> t.at(i + 1) >> x.at(i + 1) >> y.at(i + 1); }

  rep(i, N) {
    int dis = abs(x.at(i + 1) - x.at(i)) + abs(y.at(i + 1) - y.at(i));
    int dt = t.at(i + 1) - t.at(i);
    if ((dt - dis) % 2 != 0 || dt < dis) {
      break;
    } else if (i == N - 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  // ----------------------------------------------------------------
  return 0;
}