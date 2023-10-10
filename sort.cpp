#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    vector <double>  zxc = { a,b,c };
    sort(zxc.begin(), zxc.end(), greater<int>());
    for (int i = 0; i < zxc.size(); ++i)
        cout << zxc[i] << " ";
}