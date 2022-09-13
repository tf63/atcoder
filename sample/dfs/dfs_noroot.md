### 根のない木の走査
- 子ノードについての情報を用いて親ノードについての情報を更新する

- 各頂点の深さは行きがけ順に求めていて，各頂点を根とした部分木のサイズは帰りがけ順に求めている
- 木上のDFSは行きがけ順，帰りがけ順を自裁に操ることで様々な処理を行うことができる

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 木上の探索
vector<int> depth;
vector<int> subtree_size;
void dfs(const Graph &G, int v, int p, int d) {
    depth[v] = d;
    for (auto nv : G[v]) {
        if (nv == p) continue; // nv が親 p だったらダメ
        dfs(G, nv, v, d+1);
    }

    // 帰りがけ時に、部分木サイズを求める
    subtree_size[v] = 1; // 自分自身
    for (auto c : G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c]; // 子のサイズを加える
    }
}

int main() {
    // 頂点数 (木なので辺数は N-1 で確定)
    int N; cin >> N;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    int root = 0; // 仮に頂点 0 を根とする
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root, -1, 0);

    // 結果
    for (int v = 0; v < N; ++v) {
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
    }
}
```