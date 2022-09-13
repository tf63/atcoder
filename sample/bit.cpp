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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------
  int n = 5;

  // {0, 1, ..., n-1} の部分集合の全探索
  for (int bit = 0; bit < (1 << n); ++bit) {
    /* bit で表される集合の処理を書く */

    /* きちんとできていることを確認してみる */
    // bit の表す集合を求める
    vector<int> S;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // i が bit に入るかどうか
        S.push_back(i);
      }
    }

    // bit の表す集合の出力
    cout << bit << ": {";
    for (int i = 0; i < (int)S.size(); ++i) {
      cout << S[i] << " ";
    }
    cout << "}" << endl;
  }

  // ----------------------------------------------------------------
  return 0;
}