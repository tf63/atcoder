#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define ll long long
#define BIG_INT 2000000000

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "";
  cin >> s;

  int ans = 0;
  ans += s[0] - '0';
  ans += s[1] - '0';
  ans += s[2] - '0';

  cout << ans << endl;

  return 0;
}