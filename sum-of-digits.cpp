#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
#include <iostream>

int main() {
    int ilocz , a, b, test;
    int sum = 0;
    for(int i = 0 ; i <= 1; i++ ){
        cin >> test;
        break;
    }
    for(int j = 0; j< test; j++){
    cin >> a >> b;
    ilocz = a * b;
    int sum = 0;
    int originalNumber = ilocz;
    while (ilocz> 0) {
        int digit = ilocz % 10;
        sum += digit; 
        ilocz /= 10; 
    }
    ilocz = a*b;
    cout << ilocz << " " <<  sum << endl;
    }

    return 0;
}