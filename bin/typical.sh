### テストデータのダウンロードはできてない
typical=/work/contest/other/typical90

TEMPLATE="${WORKDIR}/templates/atcoder.cpp"

for ((i=0; i < 100; i++)); do
    num=$(printf "%03d\n" "${i}")
    mkdir $typical/$num/

    cp -n $TEMPLATE $typical/$num/$num.cpp
    
done