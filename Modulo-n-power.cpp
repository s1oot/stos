#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a, b, c, zxc;
    long long asd;
    for (int i = 0; i < 6; i++) {
        cin >> a >> b >> c;
        if (b % 10 == 0 && b != 0) {
            b = 10;
        }
        asd = pow(a, b);
        zxc = asd % c;
        cout << zxc << endl;
    }
}
//submit 66.67 
