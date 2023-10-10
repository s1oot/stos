#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
    double x1,y1,z1,x2,y2,z2,x3,y3,z3,d1,d2,d3,sqr,per;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
     d1 = sqrt(pow(x1-x2, 2) + pow(y1-y2,2)+ pow(z1-z2,2));
     d2 = sqrt(pow(x2-x3, 2) + pow(y2-y3,2) + pow(z2-z3,2));
     d3 = sqrt(pow(x3-x1, 2) + pow(y3-y1,2) + pow(z1-z3,2));
     per = (d1 + d2 + d3)/2; 
     sqr = sqrt(per*(per-d1)*(per-d2)*(per-d3));
    cout << sqr << endl;
return 0;
}