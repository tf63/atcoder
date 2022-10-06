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

    double a = -24.4;
    double b = 10.0;

    double c = 0;
    if (a >= 0) {
        c = a - (int)(a / b) * b;
    } else {
        c = a - (int)(a / b - 1) * b;
    }

    cout << c << endl;
}