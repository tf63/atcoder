<!-- nodejsをダウンロードしていることでコンテナがでかくなってしまっている(要修正) -->

### accのインストール先
/lib/ac-library

### ログイン
acc check-oj
acc login
oj login https://beta.atcoder.jp

### 問題のダウンロード
abc問題のダウンロード
- ./bin/abc_dl abc123
    - abcディレクトリ配下に問題がダウンロードされる

arc問題のダウンロード
- ./bin/arc_dl arc123
    - arcディレクトリ配下に問題がダウンロードされる

### テンプレート
- 解答用のcppファイルは/work/templates/atcoder.cppをコピーして作成される
- ./bin/abc_dl, ./bin/arc_dlでテンプレートファイルを選択している

### テストの実行
- 解答用のcppファイルを開いて，vscodeのタスク'test'を実行すると，例題でのテストが開始される
- oj t -d (testsディレクトリへのパス) -c (a.outへのパス)

### 解答の提出
- 解答用のcppファイルを開いて，vscodeのタスク'submit'を実行すると，自動で提出できる