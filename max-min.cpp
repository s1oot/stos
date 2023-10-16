#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        vector<int> num(t);

        for (int j = 0; j < t; j++) {
           cin >> num[j];
        }

        int min = num[0];
        int max = num[0];

        for (int j = 0; j < t; j++) {
            if (num[j] < min) {
                min = num[j];
            }
            if (num[j] > max) {
                max =  num[j];
            }
        }

        cout << min << " " << max << endl;
    }

    return 0;
}