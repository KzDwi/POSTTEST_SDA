#include <iostream>
using namespace std;

struct Mahasiswa {
    char nama[50];
    char nim[10];
    float ipk;
};

// Urutkan berdasarkan IPK ascending (bubble sort)
void urutkanMahasiswa(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                // Tukar elemen kalau nilai sebelumnya terlalu besar
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
        // Menampilkan proses sorting pada setiap iterasi (Opsional)
        // cout << endl;
        // cout << "Proses [" << i + 1 << "] :";
        // for (int k = 0; k < n; k++) {
        //     cout << " " << mhs[k].ipk;
        // }
    }
}

int main() {
    Mahasiswa mhs[4];

    // Input data mahasiswa
    for (int i = 0; i < 4; i++) {
        cout << "Input Mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }

    urutkanMahasiswa(mhs, 4);

    cout << "\n\nMahasiswa setelah diurutkan berdasarkan IPK (ascending):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    return 0;
}