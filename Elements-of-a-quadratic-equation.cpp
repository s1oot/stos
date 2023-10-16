#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c,x1,x2;
    cin >> a >> b >> c;
    double d = pow(b, 2) - 4 * a * c;
    if(a == 0 && b== 0 && c==0 ){

        cout << "N" << endl;

    }
    else if (a==0){

        cout << -c/b <<endl;

    }
    else if( d == 0 ){

        double x = -b/2*a;
        
    }
    else if (d < 0 ) {
        cout << "B" << endl;
    }
    else  {
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        cout  << x1  << " " << x2 << endl;
    }

return 0;
}