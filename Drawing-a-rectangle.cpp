#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        if (i == a - 1 || i == 0) {
            
            for (int j = 0; j <= b -1 ; j++) {
                cout << "#";
            }
        } else {
            cout << "#";
            for (int j = 1; j < b- 1; j++) {
                cout << " ";
            }
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}