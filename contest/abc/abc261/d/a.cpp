#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun>
class y_combinator_result {
    Fun fun_;

   public:
    template <class T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template <class Fun>
decltype(auto) y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container,
          typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
    os << '{';
    string sep;
    for (const T& x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int64_t> X(N);

    for (auto& x : X)
        cin >> x;

    vector<int64_t> bonus(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int c, y;
        cin >> c >> y;
        bonus[c] += y;
    }

    vector<int64_t> dp(N + 1, -INF64);
    dp[0] = 0;

    for (auto& x : X) {
        vector<int64_t> ndp(N + 1, -INF64);

        for (int c = 0; c < N; c++) {
            ndp[c + 1] = max(ndp[c + 1], dp[c] + x + bonus[c + 1]);
            ndp[0] = max(ndp[0], dp[c]);
        }

        dp.swap(ndp);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
