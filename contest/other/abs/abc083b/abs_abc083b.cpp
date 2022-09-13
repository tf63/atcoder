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

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/
#define BIG_INT 2000000000

using namespace std;

int digit_sum(int n) {
  int subsum = 0;
  rep(_, 5) {
    subsum += n % 10;
    n /= 10;
  }

  return subsum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, A, B;
  cin >> N >> A >> B;

  int sum = 0;
  int subsum = 0;

  prep(i, N) {
    subsum = digit_sum(i);

    if (A <= subsum && subsum <= B) {
      sum += i;
    }
  }

  cout << sum << endl;

  return 0;
}