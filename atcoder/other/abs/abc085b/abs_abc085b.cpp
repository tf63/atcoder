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
  vec d(N);
  rep(i, N) { cin >> d.at(i); }

  sort(all(d));

  int count = 1;
  rep(i, N - 1) {
    if (d.at(i) != d.at(i + 1)) {
      count++;
    }
  }

  cout << count << endl;
  // ----------------------------------------------------------------
  return 0;
}