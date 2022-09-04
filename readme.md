<!-- nodejsをダウンロードしていることでコンテナがでかくなってしまっている(要修正) 
-> ac-libraryはzipファイルからインストールすることも可能 -->
<!-- abc, arc以外のコンテストをotherにまとめておきたいのでabc_dl, arc_dl, other_dlに分けている -->

### accのインストール先
`/lib/ac-library`

### acc, ojのログイン
```bash
    # ダウンロードの確認
    acc check-oj 
    # accのログイン
    acc login
    # ojのログイン
    oj login https://beta.atcoder.jp
```

### accの設定の変更
デフォルトで全部の問題がダウンロードされるようになる
    
    >>> acc config default-task-choice all

### 問題のダウンロード
abc問題のダウンロード

    >>> ./bin/abc_dl abc123

- abcディレクトリ配下に問題がダウンロードされる

arc問題のダウンロード

    >>> ./bin/arc_dl arc123

- arcディレクトリ配下に問題がダウンロードされる

### テンプレート
- 解答用のcppファイルは`/work/templates/atcoder.cpp`をコピーして作成される
- ファイル`./bin/abc_dl`, `./bin/arc_dl`内でテンプレートファイルを選択している

### テストの実行
- 解答用のcppファイルを開いて，vscodeのタスク`test`を実行すると，例題でのテストが開始される
    
    oj t -d (testsディレクトリへのパス) -c (a.outへのパス)

### 解答の提出
- 解答用のcppファイルを開いて，vscodeのタスク`submit`を実行すると，自動で提出できる

### 参考
- 一連の流れ
https://qiita.com/Adaachill/items/3d4ddad56c5c2cc372cd
- タスク(compile)
https://iconcreator.hatenablog.com/entry/2021/09/19/200000
- タスク(submit, test)
https://blog.knshnb.com/posts/vscode-oj-acl/
