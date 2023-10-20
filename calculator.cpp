#include <iostream>

using namespace std;

int main()
{
    char zxc;

    int a, s;

    while (cin >> zxc)
    {
        char calul = zxc;
        switch (calul)
        {
        case '+':
            cin >> a >> s;
            cout << a + s << endl;
            break;
        case '-':
            cin >> a >> s;
            cout << a - s << endl;
            break;
        case '*':
            cin >> a >> s;
            cout << a * s << endl;            
            break;
        case '/':
            cin >> a >> s;
            if (s == 0) {
                cout << "ERROR" << endl;
                break;
            }
            else {
                cout << a / s << endl;
            }
            break;
        case '%': 
            cin >> a >> s;
            if(s == 0){
                cout << "ERROR" << endl;
            }
            else{
                cout << a % s << endl;
            } 
            break;
            }
    }
}