#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    cout << time(NULL) << "\n";
    time_t b;
    time(&b);
    cout << "b=" << b <<"\n";

    //srand(b);
    srand(123);
    // srand(3);
    
    int n = 10;
    int a[n];

    for(int i = 0; i<n; i++) {
        a[i] = rand() % 6 + 1;
    }

    for(int i = 0; i<n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";

    return 0;
}
