#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
    double x,y,z,x1,y1,z1,d;
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    d = sqrt(pow(x1 -x, 2) + pow(y1-y,2) + pow(z1-z,2));
    printf("%lf",d);
    return 0 ;
}