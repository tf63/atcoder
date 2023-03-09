#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define ll long long
#define BIG_INT 2000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;
    vector<int> v{1, 2, 3};

    do {
        for (int i = 0; i < n; i++) {
            cout << v.at(i) << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}