
#include <iostream>
using namespace std;

int main() {
    // ----------------------------------------------------------------
    int N = 150;
    for (int i = 1; i <= N; i++) {
        bool kaijou = false;
        string S = to_string(i);
        auto found = S.find('3');
        if (found != string::npos) {
            kaijou = true;
        }

        if (i % 3 == 0) {
            kaijou = true;
        }

        if (kaijou) {
            std::cout << i << "!" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }
    // ----------------------------------------------------------------
    return 0;
}