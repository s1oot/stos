#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    double a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    vector<double> zxc = {a,b,c,d}; 
    double max = *max_element(zxc.begin(), zxc.end());
    cout << max;
    return 0 ;
}