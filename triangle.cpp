#include <iostream>
#include <cmath>
using namespace std;
int main (){
int a,b,c;
cin >> a >> b >> c;
    if(c > a+b || c <= b - a || c < a-b ){
            cout << "ERROR" <<endl;
        }

    else if (pow(c,2)< pow(a,2)+pow(b,2)&& pow(b,2) < pow(c,2)+pow(a,2)&& pow(a,2) < pow(c,2)+pow(b,2)){

        cout << 1 << endl;
    }
    else {
            cout << 0 << endl;
        
        }
}