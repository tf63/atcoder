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