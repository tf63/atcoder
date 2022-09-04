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
  int N, Y;
  cin >> N >> Y;

  rep(i, N + 1) {
    krep(j, i, N + 1) {
      int sum = 10000 * i + 5000 * (j - i) + 1000 * (N - j);
      if (sum == Y) {
        cout << i << " " << j - i << " " << N - j << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  // ----------------------------------------------------------------
  return 0;
}