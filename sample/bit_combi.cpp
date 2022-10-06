// N > 32ビットは無理
// 普通に3回for文回せば良い

#include <iostream>
#include <vector>
using namespace std;

/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    int n = 5;  // {0, 1, 2, 3, 4} の部分集合を考える
    int k = 3;

    int bit = (1 << k) - 1;  // bit = {0, 1, 2}
    for (; bit < (1 << n); bit = next_combination(bit)) {
        /* ここに処理を書く */

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
}