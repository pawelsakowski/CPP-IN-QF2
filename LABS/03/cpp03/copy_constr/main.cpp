#include<iostream>
using namespace std;

int main(){

    int a = 7;
    cout << "a = " << a << "\n";

    // assignment operator
    int b = a;
    cout << "b = " << b << "\n";

    // default copy constructor
    int c(a);
    cout << "c = " << c << "\n";

    return 0;
}