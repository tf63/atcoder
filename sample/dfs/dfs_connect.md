### 連結成分の個数
- 連結とは限らない無向グラフが与えられたとき，それが何個の連結成分からなるのかを数える問題

-> まだ探索済みでない頂点vを選んでvを始点としたDFSを行うというのを全頂点が探索済みになるまで繰り返す

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 全頂点が訪問済みになるまで探索
    int count = 0;
    seen.assign(N, false);
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // v が探索済みだったらスルー
        dfs(G, v); // v が未探索なら v を始点とした DFS を行う
        ++count;
    }
    cout << count << endl;
}
```


### グリッドグラフの場合
```cpp
#include <iostream>
#include <vector>
using namespace std;

// 入力
int H, W;
vector<vector<int>> field;

// 探索
void dfs(int h, int w) {
    field[h][w] = 0;

    // 八方向を探索
    for (int dh = -1; dh <= 1; ++dh) {
        for (int dw = -1; dw <= 1; ++dw) {
            int nh = h + dh, nw = w + dw;

            // 場外アウトしたり、0 だったりはスルー
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (field[nh][nw] == 0) continue;

            // 再帰的に探索
            dfs(nh, nw);
        }
    }
}

int main() {
    // 入力受け取り
    while (cin >> W >> H) {
        if (H == 0 || W == 0) break;
        field.assign(H, vector<int>(W, 0));
        for (int h = 0; h < H; ++h) for (int w = 0; w < W; ++w) cin >> field[h][w];

        // 探索開始
        int count = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (field[h][w] == 0) continue; // 残島じゃなかったらスルー
                dfs(h, w);
                ++count;
            }
        }
        cout << count << endl;
    }
}
```