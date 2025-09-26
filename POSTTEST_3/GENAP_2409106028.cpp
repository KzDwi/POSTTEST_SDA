#include <iostream>
using namespace std;

struct Flight {
    char kodePenerbangan[20];
    char tujuan[50];
    char status[50];
    Flight* next;
    Flight* prev;  // prev untuk kembali/menuju list sebelumnya
};

Flight* head = nullptr;
Flight* tail = nullptr;  // Tambahan tail untuk DLL
int counterJadwal = 0;

// ====== Fungsi Tambah di Akhir ======
void tambahJadwal(const char kode[], const char tujuan[], const char status[]) {
    Flight* baru = new Flight;
    int i = 0;
    while (kode[i] != '\0') { baru->kodePenerbangan[i] = kode[i]; i++; } baru->kodePenerbangan[i] = '\0';
    i = 0;
    while (tujuan[i] != '\0') { baru->tujuan[i] = tujuan[i]; i++; } baru->tujuan[i] = '\0';
    i = 0;
    while (status[i] != '\0') { baru->status[i] = status[i]; i++; } baru->status[i] = '\0';
    baru->next = nullptr;
    baru->prev = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

// ====== Fungsi Sisip di Posisi Tertentu ======
void sisipJadwal(const char kode[], const char tujuan[], const char status[], int posisi) {
    Flight* baru = new Flight;
    int i = 0;
    while (kode[i] != '\0') { baru->kodePenerbangan[i] = kode[i]; i++; } baru->kodePenerbangan[i] = '\0';
    i = 0;
    while (tujuan[i] != '\0') { baru->tujuan[i] = tujuan[i]; i++; } baru->tujuan[i] = '\0';
    i = 0;
    while (status[i] != '\0') { baru->status[i] = status[i]; i++; } baru->status[i] = '\0';
    baru->next = nullptr;
    baru->prev = nullptr;

    if (posisi == 1 || head == nullptr) {
        baru->next = head;
        if (head) head->prev = baru;
        head = baru;
        if (!tail) tail = baru;
        return;
    }

    Flight* temp = head;
    int idx = 1;
    while (temp != nullptr && idx < posisi - 1) {
        temp = temp->next;
        idx++;
    }

    if (temp == nullptr) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    } else {
        baru->next = temp->next;
        baru->prev = temp;
        if (temp->next) temp->next->prev = baru;
        else tail = baru; 
        temp->next = baru;
    }
}

// ====== Fungsi Hapus Awal ======
void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    cout << "Jadwal paling awal berhasil dihapus." << endl;
}

// ====== Fungsi Update Status ======
void updateStatus(const char kodeCari[]) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    Flight* temp = head;
    while (temp != nullptr) {
        int i = 0;
        bool sama = true;
        while (kodeCari[i] != '\0' || temp->kodePenerbangan[i] != '\0') {
            if (kodeCari[i] != temp->kodePenerbangan[i]) { sama = false; break; }
            i++;
        }
        if (sama) {
            cout << "Masukkan status baru: ";
            char newStatus[50];
            cin.getline(newStatus, 50);
            i = 0;
            while (newStatus[i] != '\0') { temp->status[i] = newStatus[i]; i++; } temp->status[i] = '\0';
            cout << "Status penerbangan berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan." << endl;
}

// ====== Fungsi Tampilkan Semua (depan -> belakang) ======
void tampilkan() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    Flight* temp = head;
    cout << "\n=== Daftar Jadwal Penerbangan (DARI DEPAN) ===" << endl;
    while (temp != nullptr) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------" << endl;
        temp = temp->next;
    }
}

// ====== Fungsi Tampilkan dari Belakang (reverse) ======
void tampilkanReverse() {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    Flight* temp = tail;
    cout << "=== Daftar Jadwal Penerbangan (DARI BELAKANG) ===" << endl;
    while (temp != nullptr) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------" << endl;
        temp = temp->prev;
    }
}

// ====== Fungsi Cari Data (Linear Search) ======
void cariData(const char input[]) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    Flight* temp = head;
    bool ketemu = false;
    while (temp != nullptr) {
        bool samaKode = true, samaTujuan = true;
        int i = 0;
        // Cek kode
        while (input[i] != '\0' || temp->kodePenerbangan[i] != '\0') {
            if (input[i] != temp->kodePenerbangan[i]) { samaKode = false; break; }
            i++;
        }
        i = 0;
        // Cek tujuan
        while (input[i] != '\0' || temp->tujuan[i] != '\0') {
            if (input[i] != temp->tujuan[i]) { samaTujuan = false; break; }
            i++;
        }
        if (samaKode || samaTujuan) {
            cout << "=== DATA DITEMUKAN ===" << endl;
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            cout << "-----------------------" << endl;
            ketemu = true;
            break;
        }
        temp = temp->next;
    }
    if (!ketemu) cout << "Data tidak ditemukan." << endl;
}

// ====== Hapus Semua Data (avoid memory leak) ======
void hancurkan() {
    while (head) {
        Flight* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main() {
    char nama[50], nim[10];
    cout << "Masukkan Nama: ";
    cin.getline(nama, 50);
    cout << "Masukkan NIM : ";
    cin.getline(nim, 10);

    // ambil 3 digit terakhir NIM
    int len = 0;
    while (nim[len] != '\0') len++;
    char tigaDigit[4];
    tigaDigit[0] = nim[len - 3];
    tigaDigit[1] = nim[len - 2];
    tigaDigit[2] = nim[len - 1];
    tigaDigit[3] = '\0';
    int digitTerakhir = nim[len - 1] - '0'; // untuk posisi sisip

    int pilihan;
    do {
        cout << endl;
        cout << "+|------------------------------------------------------------|+" << endl;
        cout << "||                  SISTEM JADWAL PENERBANGAN                 " << endl;
        cout << "||    = [ " << nama << " - " << nim << " ]" << endl;
        cout << "+|------------------------------------------------------------|+" << endl;
        cout << "|| 1. Tambah Jadwal Penerbangan                              " << endl;
        cout << "|| 2. Sisipkan Jadwal Penerbangan                            " << endl;
        cout << "|| 3. Hapus Jadwal Paling Awal                               " << endl;
        cout << "|| 4. Update Status Penerbangan                              " << endl;
        cout << "|| 5. Tampilkan Semua Jadwal (dari depan)                    " << endl;
        cout << "|| 6. Tampilkan Semua Jadwal (dari belakang)                 " << endl;
        cout << "|| 7. Cari Data Penerbangan (berdasarkan kode/tujuan)        " << endl;
        cout << "|| 0. Keluar                                                 " << endl;
        cout << "+|------------------------------------------------------------|+" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        // Tambah Jadwal
        if (pilihan == 1) {
            char tujuan[50], status[50];
            cout << "Masukkan tujuan: ";
            cin.getline(tujuan, 50);
            cout << "Masukkan status: ";
            cin.getline(status, 50);

            // buat kode penerbangan
            char kode[20];
            kode[0] = 'J'; kode[1] = 'T'; kode[2] = '-';
            kode[3] = tigaDigit[0]; kode[4] = tigaDigit[1]; kode[5] = tigaDigit[2];
            int idx = 6;
            if (counterJadwal > 0) {
                kode[idx++] = '-';
                kode[idx++] = (counterJadwal + '0'); // hanya 1 digit tambahan (JT-NIM-Counter)
            }
            kode[idx] = '\0';
            tambahJadwal(kode, tujuan, status);
            counterJadwal++;
        }
        // Selipkan Jadwal (Add Specific, digit akhir + 1)
        else if (pilihan == 2) {
            char tujuan[50], status[50];
            cout << "Masukkan tujuan: ";
            cin.getline(tujuan, 50);
            cout << "Masukkan status: ";
            cin.getline(status, 50);

            char kode[20];
            kode[0] = 'J'; kode[1] = 'T'; kode[2] = '-';
            kode[3] = tigaDigit[0]; kode[4] = tigaDigit[1]; kode[5] = tigaDigit[2];
            int idx = 6;
            if (counterJadwal > 0) {
                kode[idx++] = '-';
                kode[idx++] = (counterJadwal + '0');
            }
            kode[idx] = '\0';
            int posisi = digitTerakhir + 1; //Posisi sisipkan
            sisipJadwal(kode, tujuan, status, posisi);
            counterJadwal++;
        } 
        // Hapus Jadwal Awal
        else if (pilihan == 3) {
            hapusAwal();
        } 
        // Update Penerbangan
        else if (pilihan == 4) {
            cout << "Masukkan kode penerbangan yang ingin diupdate: ";
            char kodeCari[20];
            cin.getline(kodeCari, 20);
            updateStatus(kodeCari);
        } 
        // Tampilkan Jadwal dari depan
        else if (pilihan == 5) {
            tampilkan();
        } 
        // Tampilkan Jadwal dari belakang
        else if (pilihan == 6) {
            tampilkanReverse();
        }
        // Cari Data Penerbangan
        else if (pilihan == 7) {
            cout << "Masukkan kode atau tujuan: ";
            char input[50];
            cin.getline(input, 50);
            cariData(input);
        }

    } while (pilihan != 0);

    hancurkan();
    return 0;
}