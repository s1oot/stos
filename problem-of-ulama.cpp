#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int n, test, iter;
    iter = 0;
    cin >> test;
    for (int i = 0; i < test; i++ ){
        cin >> n;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
                iter++;

            }
            else {
                n = 3 * n + 1;
                iter++;
            } 
        }
        cout << iter << endl;
        iter = 0;
    }
}
