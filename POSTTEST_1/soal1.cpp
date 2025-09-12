#include <iostream>
using namespace std;

// Fungsi untuk membalik array menggunakan pointer
void balikArray(int *DataArray, int n) {
    int *awal = DataArray;
    int *akhir = DataArray + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int DataArray[7] = {2, 3, 5, 7, 11, 13, 17}; // tujuh bilangan prima

    cout << "Array sebelum dibalik : "; // Posisi normal array
    for (int i = 0; i < 7; i++) {
    cout << DataArray[i] << " ";
    }
    cout << endl;

    // cout << "Array setelah dibalik (Tanpa pointer): "; // Posisi array setelah dibalik (Tanpa pointer, untuk pengecekan)
    // for (int i = 6; i > 0; i--) {
    // cout << DataArray[i] << " ";
    // }
    // cout << endl;

    balikArray(DataArray, 7); //Fungsi membalik bilangan pada array

    cout << "Array sesudah dibalik : "; //Verifikasi isi array
    for (int i = 0; i < 7; i++) {
    cout << DataArray[i] << " ";
    }
    cout << endl;

    return 0;
}