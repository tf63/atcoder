
#include <iostream>
using namespace std;

int main() {
    // ----------------------------------------------------------------
    int N = 150;

    for (int i = 1; i <= N; i++) {
        bool kaijou = false;
        if (i % 3 == 0) {
            kaijou = true;
        }

        if (i % 10 == 3) {
            kaijou = true;
        }

        if (i >= 30 && i <= 39) {
            kaijou = true;
        }

        if (i >= 130 && i <= 139) {
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