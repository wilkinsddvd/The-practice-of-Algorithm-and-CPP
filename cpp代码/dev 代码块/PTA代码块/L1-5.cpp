#include <iostream>

using namespace std;

int main() {
    long long x;
    cin >> x;
    long long s = 1, n = 0;
    while (1) {
        long long t = x / s;
        if (t == 0) {
            break;
        }
        x %= s;
        s *= t;
        n += t > 9 ? 1 : t;
    }
    cout << s << " " << n << endl;
    return 0;
}
