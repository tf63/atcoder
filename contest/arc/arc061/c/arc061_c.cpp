#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
    cout << i;
  }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()
/*
  vector<int> v = {2, 3, 1}
  sort(all(v))
*/

#define INF 2000000000
#define MINF -200000000

vecll pow_vecll{1,        10,        100,        1000,        10000,        100000,       1000000,
                10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}

ll stack_sum(stack<int>& s) {
    int i = 0;
    ll sum = 0;
    while (!s.empty()) {
        sum += s.top() * pow_vecll.at(i);
        s.pop();
        i++;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ----------------------------------------------------------------
    string S;
    cin >> S;

    int N = (int)S.size();
    stack<int> s;
    ll subsum = 0;
    ll sum = 0;

    for (int bit = 0; bit < (1 << (N - 1)); bit++) {
        subsum = 0;
        for (int i = 0; i < N - 1; i++) {
            s.push(S.at(i) - '0');
            if (bit & (1 << i)) {
                // i
                subsum += stack_sum(s);
            }
        }
        s.push(S.at(N - 1) - '0');
        subsum += stack_sum(s);

        sum += subsum;
    }

    cout << sum << endl;
    // ----------------------------------------------------------------
    return 0;
}