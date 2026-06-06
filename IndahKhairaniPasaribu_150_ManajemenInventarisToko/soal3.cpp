#include <iostream> // buat input dan output
#include <vector>   // buat menyimpan data barang
#include <cstdlib>
using namespace std;

// data setiap barang disimpan dalam struct
struct Barang {
    string kode;
    string nama;
    int harga;
    int stok;
};

vector<Barang> daftarBarang; // vector untuk menyimpan semua data barang

// fungsi tambah barang
void tambahBarang() {

    Barang b;

    cout << "==TAMBAH BARANG==" << endl;

    cout << "Kode Barang : ";
    cin >> b.kode;

    cin.ignore();

    cout << "Nama Barang : ";
    getline(cin, b.nama);

    // harga tidak boleh negatif
    do {
        cout << "Harga Barang : " ;
        cin >> b.harga;

        if (b.harga < 0) {
            cout << "Harga tidak boleh negatif!" <<endl;
        }

    } while (b.harga < 0);

    // stok tidak boleh negatif
    do {
        cout << "Stok Barang : ";
        cin >> b.stok;

        if (b.stok < 0) {
            cout << "Stok tidak boleh negatif!" << endl;
        }

    } while (b.stok < 0);

    daftarBarang.push_back(b);

    cout << "Barang berhasil ditambahkan" << endl;
}

// fungsi menampilkan semua barang
void tampilBarang() {

    cout << "== DAFTAR BARANG ==" << endl;

    if (daftarBarang.empty()) {
        cout << "Belum ada data barang " << endl;
        return;
    }

    for (int i = 0; i < daftarBarang.size(); i++) {

        cout << "Kode  : "
             << daftarBarang[i].kode << endl;

        cout << "Nama  : "
             << daftarBarang[i].nama << endl;

        cout << "Harga : "
             << daftarBarang[i].harga << endl;

        cout << "Stok  : "
             << daftarBarang[i].stok << endl;

        cout << "----------------------" << endl;
    }
}

// fungsi mencari barang dengan harga tertinggi
void cariBarangTermahal() {

    if (daftarBarang.empty()) {

        cout << "Data barang masih kosong";
        return;
    }

    int index = 0;

    // mencari harga terbesar
    for (int i = 1; i < daftarBarang.size(); i++) {

        if (daftarBarang[i].harga >
            daftarBarang[index].harga) {

            index = i;
        }
    }

    cout << "== BARANG TERMAHAL ==" << endl;

    cout << "Kode  : "
         << daftarBarang[index].kode << endl;

    cout << "Nama  : "
         << daftarBarang[index].nama << endl;

    cout << "Harga : "
         << daftarBarang[index].harga << endl;

    cout << "Stok  : "
         << daftarBarang[index].stok << endl;
}

// fungsi menghitung total nilai inventaris
void totalInventaris() {

    int total = 0;

    // harga dikali stok untuk setiap barang
    for (int i = 0; i < daftarBarang.size(); i++) {

        total += daftarBarang[i].harga *
                 daftarBarang[i].stok;
    }

    cout << "== TOTAL NILAI INVENTARIS ==" << endl;
    cout << "Total Nilai Inventaris : "
         << total << endl;
}

// fungsi cek barang yang perlu direstock
void cekRestock() {

    cout << "== BARANG YANG PERLU DIRESTOCK ==" <<endl;

    bool ditemukan = false;

    for (int i = 0; i < daftarBarang.size(); i++) {

        if (daftarBarang[i].stok < 5) {

            ditemukan = true;

            cout << daftarBarang[i].nama
                 << " | Stok : "
                 << daftarBarang[i].stok
                 << endl;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada barang yang perlu direstock";
    }
}

// update stok menggunakan pointer
void updateStok() {

    string kode;

    cout << "Masukkan kode barang : ";
    cin >> kode;

    for (int i = 0; i < daftarBarang.size(); i++) {

        if (daftarBarang[i].kode == kode) {

            // pointer diarahkan ke stok barang
            int* ptrStok = &daftarBarang[i].stok;

            int perubahan;

            cout << "Stok saat ini : "
                 << *ptrStok << endl;

            cout << "Masukkan perubahan stok (+ tambah, - kurangi) : ";
            cin >> perubahan;

            // jangan sampai stok jadi negatif
            if (*ptrStok + perubahan < 0) {

                cout << "Stok tidak boleh negatif";

            } else {

                // mengubah stok melalui pointer
                *ptrStok += perubahan;

                cout << "Stok berhasil diupdate" << endl;
                cout << "Stok sekarang : "
                     << *ptrStok << endl;
            }

            return;
        }
    }

    cout << "Barang tidak ditemukan";
}

int main() {
    system ("cls");
    int pilih;

    do {

        cout << "== MENU INVENTARIS ==" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Barang" << endl;
        cout << "3. Cari Barang Termahal" << endl;
        cout << "4. Total Nilai Inventaris" << endl;
        cout << "5. Cek Restock" << endl;
        cout << "6. Update Stok" << endl;
        cout << "7. Keluar";

        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih) {

        case 1:
            tambahBarang();
            break;

        case 2:
            tampilBarang();
            break;

        case 3:
            cariBarangTermahal();
            break;

        case 4:
            totalInventaris();
            break;

        case 5:
            cekRestock();
            break;

        case 6:
            updateStok();
            break;

        case 7:
            cout << "Program selesai";
            break;

        default:
            cout << "Pilihan tidak valid";
        }

    } while (pilih != 7);

}

