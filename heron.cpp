#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int  a,b,c;
    double sqr,per,per2;
    cin >> a;
    cin >> b;
    cin >> c;
    per = a+b+c;
    per2 = per/2;
    sqr = sqrt((per2)*(per2-a)*(per2-b)*(per2-c));
    cout << sqr;
    return 0;
}