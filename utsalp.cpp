#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Buku {
    string kode;
    string judul;
    string penulis;
    int stok;
};

Buku dataBuku[100];
int jumlahBuku = 0;

// ================= LOGIN =================
void login() {
    string username, password;

    cout << "===== LOGIN DIGILIB =====" << endl;
    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    cout << "\nLogin berhasil!\n" << endl;
}

// ================= TAMBAH BUKU =================
void tambahBuku() {
    cout << "\n===== TAMBAH BUKU =====" << endl;

    cout << "Kode Buku   : ";
    cin >> dataBuku[jumlahBuku].kode;
    cin.ignore();

    cout << "Judul Buku  : ";
    getline(cin, dataBuku[jumlahBuku].judul);

    cout << "Penulis     : ";
    getline(cin, dataBuku[jumlahBuku].penulis);

    cout << "Stok Buku   : ";
    cin >> dataBuku[jumlahBuku].stok;

    jumlahBuku++;

    cout << "\nData buku berhasil ditambahkan!\n";
}

// ================= LIHAT BUKU =================
void lihatBuku() {
    cout << "\n===== DATA BUKU =====" << endl;

    if (jumlahBuku == 0) {
        cout << "Belum ada data buku.\n";
    } else {
        for (int i = 0; i < jumlahBuku; i++) {
            cout << "\nBuku ke-" << i + 1 << endl;
            cout << "Kode Buku : " << dataBuku[i].kode << endl;
            cout << "Judul     : " << dataBuku[i].judul << endl;
            cout << "Penulis   : " << dataBuku[i].penulis << endl;
            cout << "Stok      : " << dataBuku[i].stok << endl;
        }
    }
}

// ================= HAPUS BUKU =================
void hapusBuku() {
    string kode;
    bool ditemukan = false;

    cout << "\n===== HAPUS BUKU =====" << endl;
    cout << "Masukkan kode buku : ";
    cin >> kode;

    for (int i = 0; i < jumlahBuku; i++) {
        if (dataBuku[i].kode == kode) {
            ditemukan = true;

            for (int j = i; j < jumlahBuku - 1; j++) {
                dataBuku[j] = dataBuku[j + 1];
            }

            jumlahBuku--;

            cout << "Data buku berhasil dihapus!\n";
            break;
        }
    }

    if (!ditemukan) {
        cout << "Kode buku tidak ditemukan!\n";
    }
}

// ================= REKURSIF TOTAL STOK =================
int totalStok(int index) {
    if (index == jumlahBuku) {
        return 0;
    }

    return dataBuku[index].stok + totalStok(index + 1);
}

// ================= SIMPAN FILE =================
void simpanFile() {
    ofstream file("buku.txt");

    for (int i = 0; i < jumlahBuku; i++) {
        file << dataBuku[i].kode << "|";
        file << dataBuku[i].judul << "|";
        file << dataBuku[i].penulis << "|";
        file << dataBuku[i].stok << endl;
    }

    file.close();

    cout << "\nData berhasil disimpan ke buku.txt\n";
}

// ================= MENU =================
void menu() {
    int pilihan;

    do {
        cout << "\n===== MENU UTAMA DIGILIB =====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Lihat Buku" << endl;
        cout << "4. Total Stok Buku" << endl;
        cout << "5. Simpan ke File" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;

            case 2:
                hapusBuku();
                break;

            case 3:
                lihatBuku();
                break;

            case 4:
                cout << "\nTotal seluruh stok buku : "
                     << totalStok(0) << endl;
                break;

            case 5:
                simpanFile();
                break;

            case 6:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }

    } while (pilihan != 6);
}

// ================= MAIN =================
int main() {
    login();
    menu();

    return 0;
}
