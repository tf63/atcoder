#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
    cout << i;
  }
*/

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/
#define BIG_INT 2000000000

using namespace std;

void print_vec(vec v) {
  rep(i, (int)v.size()) { cout << v.at(i); }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vec a(N);
  rep(i, N) { cin >> a.at(i); }

  sort(all(a), greater<int>());

  int point_alice = 0;
  int point_bob = 0;
  rep(i, N) {
    if (i % 2 == 0) {
      point_alice += a.at(i);
    } else {
      point_bob += a.at(i);
    }
  }

  cout << point_alice - point_bob << endl;
  return 0;
}