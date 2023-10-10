#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
    double x,y,r,x1,y1,r1,d;
    cin >> x>>y>>r>>x1>>y1>>r1;
     d = sqrt(pow(x-x1, 2)+pow(y-y1,2));
    if(d > (r+r1)){
        cout << "F" << endl;
    }
    else if(r> (d+r1) ){
        cout << "F" << endl;
    }
    else{
    cout << "T" << endl;
    }
return 0;
}