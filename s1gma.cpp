#include<iostream>

using namespace std;

void sigma(int zxc) {
  int summa = 0;
  for (int i = 1; i <= zxc; ++i) {
    if (zxc % i == 0) {
      summa += i;
    }
  }
  if (zxc * 2 == summa){
    cout << summa << " " << "P" << endl;
  }
  else {
    cout << summa << endl;
  }  
}

int main() {
  int n;
  for ( ;cin >> n; ){
    sigma(n);
  }
  return 0;
}