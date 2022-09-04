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
#define BIG_INT 2000000000

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, C, X;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;

  int count = 0;
  rep(a, A + 1) {
    rep(b, B + 1) {
      rep(c, C + 1) {
        if (a * 500 + b * 100 + c * 50 == X) {
          count++;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}