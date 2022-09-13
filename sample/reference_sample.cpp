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

vector<int> pow_vec{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int stack_sum(stack<int>& s) {
    int i = 0;
    int sum = 0;
    while (!s.empty()) {
        sum += s.top() * pow_vec.at(i);
        s.pop();
        i++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    int a = stack_sum(s);
    if (s.empty()) {
        cout << "empty ";
    }
    cout << a << " " << s.empty() << endl;
}