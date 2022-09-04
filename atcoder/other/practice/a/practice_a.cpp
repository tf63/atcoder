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

  int a, b, c;
  string s;
  cin >> a;
  cin >> b >> c;
  cin >> s;

  cout << a + b + c << " " << s << endl;

  return 0;
}