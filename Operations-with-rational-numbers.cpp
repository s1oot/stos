#include <iostream>

using namespace std;

int NOD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    char qwe, zxc;
    int qwer;
    int a, s;
    int d, f;
    int z, x;

    while (cin >> zxc)
    {
        char calul = zxc;
        switch (calul)
        {
        case 'A':
            cin >> a >> qwe >> s;
            break;
        case 'B':
            cin >> d >> qwe >> f;
            break;
        case '+':
            if (f == s)
            {
                z = a + d;
                x = f;
            }
            else
            {
                z = a * f + s * d;
                x = s * f;
            }
            qwer = NOD(z, x);
            if (qwer == -1) {
                cout << z << qwe << x << endl;
            }
            else {
                cout << z / qwer << qwe << x / qwer << endl;
            }
            break;
        case '-':
            if (f == s)
            {
                z = a - d;
                x = f;
            }
            else
            {
                z = a * f - d * s;
                x = s * f;
            }
            qwer = NOD(z, x);
            if (z < 0 && x < 0)
            {
                z = -z;
                x = -x;
            }
            if (qwer == -1) {
                cout << z << qwe << x << endl;
            }
            else {
                cout << z / qwer << qwe << x / qwer << endl;
            }
            break;
        case '*':
                
                z = a * d;
                x = s * f;
                qwer = NOD(z, x);
                if (qwer == -1) {
                    cout << z << qwe << x << endl;
                }
                else {
                    cout << z / qwer << qwe << x / qwer << endl;
                }
            
            break;
        case '/':
            
                z = a * f;
                x = d * s;
                if (x < 0){

                z *= -1;
                x *= -1;
             }       
            qwer = NOD(z, x);
            if (qwer == -1) {
                cout << z << qwe << x << endl;
            }
            else {
                cout << z / qwer << qwe << x / qwer << endl;
            }
            break;
        }
    }
}