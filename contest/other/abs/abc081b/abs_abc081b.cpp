#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define ll long long
#define INF 2000000000

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N = 0;
  cin >> N;

  int ai = 0;
  int cmin = INF;  // ans
  int count = 0;

  for (int i = 0; i < N; i++) {
    cin >> ai;
    count = 0;
    while (ai % 2 == 0) {
      ai /= 2;
      count++;
    }

    cmin = min(cmin, count);
  }

  cout << cmin << endl;
  return 0;
}