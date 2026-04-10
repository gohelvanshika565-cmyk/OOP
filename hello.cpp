#include <iostream>
using namespace std;

void f(int x) {
    if (x > 0) {
        cout << x << " ";
        f(x - 2);
        cout << x << " ";
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    f(n);

    return 0;
}