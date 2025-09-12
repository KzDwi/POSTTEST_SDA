#include <iostream>
using namespace std;

// Fungsi Tukar
void tukar(int &a, int &b) { //Pakai alias (reference) dimana a = x, dan b = y
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "Sebelum tukar: x=" << x << " y=" << y << endl;
    tukar(x, y);
    cout << "Sesudah tukar: x=" << x << " y=" << y << endl;

    return 0;
}