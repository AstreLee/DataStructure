#include <iostream>
using namespace std;
int main() {
    int target[] = {2, 0, 2, 3};
    long temp = 0;
    int pos = 3;
    long count = 0;
    for (long i = 12345678; i <= 98765432; ++i) {
        temp = i;
        pos = 3;
        while (temp > 0) {
            if (temp % 10 == target[pos]) {
                --pos;
            }
            if (pos == -1) {
                ++count;
                break;
            }
            temp /= 10;
        }
    }
    cout << 98765432 - 12345678 + 1 - count << endl;
    return 0;
}