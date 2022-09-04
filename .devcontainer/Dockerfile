# Ubuntuの公式コンテナを軸に環境構築
# 22.04ではaptからpython3.8が入っていなかったので20.04で固定する
FROM ubuntu:20.04

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

# インフラを整備
RUN apt update && \
    apt install -y time tzdata tree git curl

# # C++, Python3, PyPy3の3つの環境想定
RUN apt install -y gcc-9 g++-9 gdb python3.8 python3-pip  nodejs npm

# # C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# # コンテスト補助アプリケーションをインストール
RUN pip install online-judge-tools==11.5.1
RUN npm install -g atcoder-cli@2.2.0

# 起動シェルをshからbashに変更
SHELL ["/bin/bash", "-c"]

# ユーザー名を指定
ARG USERNAME=user
ARG GROUPNAME=user

# UID, GIDはidコマンドで確認し，ログインユーザーのUID, GIDを指定する
ARG UID=1000
ARG GID=1000

# ユーザーを作成
RUN groupadd -g $GID $GROUPNAME && \ 
    useradd -m -u $UID -g $GID -s /bin/bash $USERNAME

# 初期ユーザーの変更
USER $USERNAME

WORKDIR /work
