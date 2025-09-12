#include <iostream>
using namespace std;

// Fungsi hitung baris genap
int jumlahBarisGenap(int matriks[3][3]) {
    int jumlah = 0;
    for (int i = 0; i < 3; i = 1) { //perulangan baris
        if ((i + 1) % 2 == 0) { // cek baris genap (indeks genap mulai dari 1)
            for (int j = 0; j < 3; j++) { //perulangan kolom
                jumlah += matriks[i][j];
            }
        }
    }
    return jumlah;
}

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:\n";
    for (int i = 0; i < 3; i++) { // Ambil baris
        for (int j = 0; j < 3; j++) { // Ambil kolom
            cout << matriks[i][j] << " "; //Print elemen
        }
        cout << endl;
    }

    int hasil = jumlahBarisGenap(matriks);
    cout << "Jumlah elemen baris genap = " << hasil << endl;

    return 0;
}