### 全探索
あなたは、500 円玉を A 枚、100 円玉を B 枚、50 円玉を C 枚持っています。 これらの硬貨の中から何枚かを選び、合計金額をちょうど X 円にする方法は何通りありますか

  rep(a, A + 1) {
    rep(b, B + 1) {
      rep(c, C + 1) {
        if (a * 500 + b * 100 + c * 50 == X) {
          count++;
        }
      }
    }
  }

### 1以上N以下
prep(1, N)

### ソート
- 昇順
sort(all(v))
- 降順
sort(all(v), greater<int>())

### 後ろからみる
 dream dreamer erase eraser

### DFSの計算量
DFS 全体においてすべての頂点を一通り調べることになるので、それに要する時間が O(N)O(N)
DFS 再帰関数においてすべての枝を一通り調べることになるので、それに要する時間が  O(M)

### vectorの初期化

	vector<bool> seen;
	vector<int> first_order;  // 行きがけ順
	vector<int> last_order;   // 帰りがけ順

	seen.assign(N, false);  // 全頂点を「未訪問」に初期化
	first_order.resize(N);
	last_order.resize(N);

	
	bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化
		