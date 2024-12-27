#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data buku
struct Buku {
    string kode, judul, penulis, penerbit, kotaTerbit;
    int tahunTerbit, jumlah;
    double hargaBeli;
};

// Fungsi untuk menambah buku
void tambahBuku(vector<Buku> &dataBuku) {
    Buku bukuBaru;
    cout << "\nMasukkan Kode Buku: ";
    cin >> bukuBaru.kode;
    cin.ignore();
    cout << "Masukkan Judul Buku: ";
    getline(cin, bukuBaru.judul);
    cout << "Masukkan Penulis: ";
    getline(cin, bukuBaru.penulis);
    cout << "Masukkan Penerbit: ";
    getline(cin, bukuBaru.penerbit);
    cout << "Masukkan Kota Terbit: ";
    getline(cin, bukuBaru.kotaTerbit);
    cout << "Masukkan Tahun Terbit: ";
    cin >> bukuBaru.tahunTerbit;
    cout << "Masukkan Harga Beli: ";
    cin >> bukuBaru.hargaBeli;
    cout << "Masukkan Jumlah Buku: ";
    cin >> bukuBaru.jumlah;

    dataBuku.push_back(bukuBaru);
    cout << "\nBuku berhasil ditambahkan!" << endl;
}

// Fungsi untuk melihat semua buku
void lihatBuku(const vector<Buku> &dataBuku) {
    if (dataBuku.empty()) {
        cout << "\nTidak ada buku yang tersedia." << endl;
        return;
    }

    cout << "\nDaftar Buku:" << endl;
    for (size_t i = 0; i < dataBuku.size(); ++i) {
        cout << i + 1 << ". Kode: " << dataBuku[i].kode
             << ", Judul: " << dataBuku[i].judul
             << ", Penulis: " << dataBuku[i].penulis
             << ", Penerbit: " << dataBuku[i].penerbit
             << ", Tahun: " << dataBuku[i].tahunTerbit
             << ", Kota: " << dataBuku[i].kotaTerbit
             << ", Harga: " << dataBuku[i].hargaBeli
             << ", Jumlah: " << dataBuku[i].jumlah << endl;
    }
}

// Fungsi untuk mengedit buku
void editBuku(vector<Buku> &dataBuku) {
    if (dataBuku.empty()) {
        cout << "\nTidak ada buku yang tersedia untuk diedit." << endl;
        return;
    }

    string kode;
    cout << "\nMasukkan Kode Buku yang ingin diedit: ";
    cin >> kode;

    for (size_t i = 0; i < dataBuku.size(); ++i) {
        if (dataBuku[i].kode == kode) {
            cout << "Masukkan data baru:" << endl;
            cin.ignore();
            cout << "Judul: ";
            getline(cin, dataBuku[i].judul);
            cout << "Penulis: ";
            getline(cin, dataBuku[i].penulis);
            cout << "Penerbit: ";
            getline(cin, dataBuku[i].penerbit);
            cout << "Kota Terbit: ";
            getline(cin, dataBuku[i].kotaTerbit);
            cout << "Tahun Terbit: ";
            cin >> dataBuku[i].tahunTerbit;
            cout << "Harga Beli: ";
            cin >> dataBuku[i].hargaBeli;
            cout << "Jumlah Buku: ";
            cin >> dataBuku[i].jumlah;

            cout << "\nBuku berhasil diedit!" << endl;
            return;
        }
    }

    cout << "\nBuku dengan kode " << kode << " tidak ditemukan!" << endl;
}

// Fungsi untuk menghapus buku
void hapusBuku(vector<Buku> &dataBuku) {
    if (dataBuku.empty()) {
        cout << "\nTidak ada buku yang tersedia untuk dihapus." << endl;
        return;
    }

    string kode;
    cout << "\nMasukkan Kode Buku yang ingin dihapus: ";
    cin >> kode;

    for (size_t i = 0; i < dataBuku.size(); ++i) {
        if (dataBuku[i].kode == kode) {
            dataBuku.erase(dataBuku.begin() + i);
            cout << "\nBuku berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "\nBuku dengan kode " << kode << " tidak ditemukan!" << endl;
}

// Fungsi utama
int main() {
    vector<Buku> dataBuku;
    int pilihan;

    do {
        cout << "\n==========================================" << endl;
        cout << "            APLIKASI DATA BUKU            " << endl;
        cout << "==========================================" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Lihat Buku" << endl;
        cout << "3. Edit Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku(dataBuku);
                break;
            case 2:
                lihatBuku(dataBuku);
                break;
            case 3:
                editBuku(dataBuku);
                break;
            case 4:
                hapusBuku(dataBuku);
                break;
            case 5:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
