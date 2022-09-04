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
  string S;
  cin >> S;
  int n = (int)S.size();
  int id = n;

  while (true) {
    if (S.substr(id - 5, 5) == "dream" || S.substr(id - 5, 5) == "erase") {
      id -= 5;
    } else if (S.substr(id - 6, 6) == "eraser") {
      id -= 6;
    } else if (S.substr(id - 7, 7) == "dreamer") {
      id -= 7;
    } else {
      break;
    }

    if (id == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  // ----------------------------------------------------------------
  return 0;
}