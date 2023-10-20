#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, char> rom;

int size(int s) {
    int a = 0;
    while (s != 0) {
        a += 1;
        s /= 10;
    }
    return a;
}

string convert(int z, int ilocz) {
    string result = "";
    if (z == 9) {
        result += rom[ilocz];
        result += rom[ilocz * 10];
    }
    else if (z >= 5) {
        result += rom[5 * ilocz];
        for (int i = 0; i < z - 5; i++) {
            result += rom[ilocz];
        }
    }
    else if (z == 4) {
        result += rom[ilocz];
        result += rom[5 * ilocz];
    }
    else {
        for (int i = 0; i < z; i++) {
            result += rom[ilocz];
        }
    }
    return result;
}

int main() {
    rom = {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000, 'M'}
    };

    int s, sz;
    string t;
    t = "";
    while (cin >> s) {
        t = "";
        sz = size(s);
        int ilocz = 1;
        for (int i = 1; i < sz; i++) {
            ilocz *= 10;
        }
        while (ilocz >= 1) {
            int z = s / ilocz;
            s = s % ilocz;
            t += convert(z, ilocz);
            ilocz /= 10;
        }
        cout << t << endl;
    }

    return 0;
}
