#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Petugas {
    string nama;
    string id;
};

struct RiwayatParkir {
    string platMobil;
    string merkMobil;
    string warnaMobil;
    int jam, menit, detik;
    int totalBiaya;
};

class Mobil {
private:
    string platMobil;
    string merkMobil;
    string warnaMobil;
    time_t waktuMasuk;

public:
    Mobil(string plat, string merk, string warna) {
        platMobil = plat;
        merkMobil = merk;
        warnaMobil = warna;
        waktuMasuk = time(0); 
    }

    string getPlat() const { return platMobil; }
    string getMerk() const { return merkMobil; }
    string getWarna() const { return warnaMobil; }
    time_t getWaktuMasuk() const { return waktuMasuk; }
};

void tampilkanHeader();
void tampilkanMenu(const Petugas* p); 
void tambahKendaraan(vector<Mobil>& daftarMobil); 
void tampilkanDaftarKendaraan(const vector<Mobil>& daftarMobil);
void prosesPembayaran(vector<Mobil>& daftarMobil, vector<RiwayatParkir>& daftarRiwayat);
void hitungDurasi(time_t masuk, int& jam, int& menit, int& detik);
void tampilkanInformasiKapasitas(const vector<Mobil>& daftarMobil);
void tampilkanRiwayatKeluar(const vector<RiwayatParkir>& daftarRiwayat);

const int MAKSIMAL_PARKIR = 20;

int main() {
    Petugas petugasHariIni;
    vector<Mobil> daftarMobil; 
    vector<RiwayatParkir> daftarRiwayat; 
    int opsi = 0;

    tampilkanHeader();
    cout << "Kami senang Anda telah hadir.\n";
    cout << "Sebelum melanjutkan, silahkan masukkan informasi Anda yang akan bertugas hari ini.\n\n";

    cout << "Masukkan nama : ";
    getline(cin, petugasHariIni.nama);
    cout << "Masukkan ID   : ";
    getline(cin, petugasHariIni.id);
    
    do {
        tampilkanMenu(&petugasHariIni); 
        cout << "Masukkan opsi : ";
        cin >> opsi;
        cin.ignore(10000, '\n');

        switch (opsi) {
            case 1:
                tambahKendaraan(daftarMobil);
                break;
            case 2:
                tampilkanDaftarKendaraan(daftarMobil);
                break;
            case 3:
                prosesPembayaran(daftarMobil, daftarRiwayat);
                break;
            case 4:
                break;
            case 5:
                tampilkanInformasiKapasitas(daftarMobil);
                break;
            case 6:
                tampilkanRiwayatKeluar(daftarRiwayat);
                break;
            default:
                break;
        }
    } while (opsi != 4);

    return 0;
}


void tampilkanHeader() {
    cout << "========================================================================\n";
    cout << "----------------------- S E L A M A T  D A T A N G ---------------------\n";
    cout << "                        DI PORTAL PARKIR KHUSUS MOBIL                   \n";
    cout << "                                MALL PRIENAL                            \n";
    cout << "========================================================================\n";
}

void tampilkanMenu(const Petugas* p) {
    cout << "\n========================================================================\n";
    cout << "Nama Petugas : " << p->nama << "\n";
    cout << "ID Petugas   : " << p->id << "\n\n";
    cout << "                    TERIMA KASIH ATAS KERJASAMANYA !                    \n";
    cout << "                - - - - S E L A M A T  B E R T U G A S - - - -          \n";
    cout << "========================================================================\n";
    cout << "Silahkan input opsi berikut dalam bentuk angka.\n";
    cout << "1. Tambahkan Daftar Kendaraan\n";
    cout << "2. Tampilkan Daftar Kendaraan\n";
    cout << "3. Pembayaran\n";
    cout << "4. Keluar Program\n";
    cout << "5. Informasi Kapasitas Parkir\n"; 
    cout << "6. Tampilkan Riwayat Kendaraan Keluar\n"; // [FITUR BARU] Tambahan opsi menu
}

void hitungDurasi(time_t masuk, int& jam, int& menit, int& detik) {
    time_t sekarang = time(0);
    double selisih = difftime(sekarang, masuk); 
    
    jam = (int)selisih / 3600;
    selisih -= jam * 3600;
    menit = (int)selisih / 60;
    selisih -= menit * 60;
    detik = (int)selisih;
}

void tampilkanInformasiKapasitas(const vector<Mobil>& daftarMobil) {
    int terparkir = daftarMobil.size();
    int tersisa = MAKSIMAL_PARKIR - terparkir;

    cout << "\n--- INFORMASI KAPASITAS PARKIR ---\n";
    cout << "Kapasitas Maksimum  : " << MAKSIMAL_PARKIR << "\n";
    cout << "Kendaraan Terparkir : " << terparkir << "\n";
    cout << "Kapasitas Tersisa   : " << tersisa << "\n";
    cout << "----------------------------------\n";
}

void tambahKendaraan(vector<Mobil>& daftarMobil) {
    int jumlah;
    cout << "Masukan jumlah mobil yang akan di parkirkan : ";
    cin >> jumlah;
    cin.ignore(10000, '\n');

    if (daftarMobil.size() + jumlah > MAKSIMAL_PARKIR) {
        cout << "Maaf, parkiran hanya dapat memuat 20 mobil.\n";
        return; 
    }
    
    int batasMasuk = jumlah;

    for (int i = 0; i < batasMasuk; i++) {
        string plat, merk, warna;
        cout << "Mobil ke " << daftarMobil.size() + 1 << "\n";
        cout << "Masukkan plat mobil  : ";
        getline(cin, plat);
        cout << "Masukkan merk mobil  : ";
        getline(cin, merk);
        cout << "Masukkan warna mobil : ";
        getline(cin, warna);
        cout << "\n";

        Mobil mobilBaru(plat, merk, warna);
        daftarMobil.push_back(mobilBaru);
    }
}

void tampilkanDaftarKendaraan(const vector<Mobil>& daftarMobil) {
    cout << "DAFTAR MOBIL YANG SUDAH TERPARKIR :\n";
    cout << "========================================================================\n";
    
    if (daftarMobil.empty()) {
        return;
    }

    for (size_t i = 0; i < daftarMobil.size(); i++) {
        int jam, menit, detik;
        hitungDurasi(daftarMobil[i].getWaktuMasuk(), jam, menit, detik);

        cout << "Mobil ke-" << (i + 1) << "\n";
        cout << "Plat mobil   : " << daftarMobil[i].getPlat() << "\n";
        cout << "Merk mobil   : " << daftarMobil[i].getMerk() << "\n";
        cout << "Warna mobil  : " << daftarMobil[i].getWarna() << "\n";
        cout << "Waktu parkir : " << jam << " jam " << menit << " menit " << detik << " detik\n";
        cout << "========================================================================\n";
    }
}

void prosesPembayaran(vector<Mobil>& daftarMobil, vector<RiwayatParkir>& daftarRiwayat) {
    tampilkanDaftarKendaraan(daftarMobil);

    if (daftarMobil.empty()) return;

    string platDicari;
    bool ditemukan = false;

    while (!ditemukan) {
        cout << "Masukkan plat mobil yang ingin dibayar : ";
        getline(cin, platDicari);

        for (size_t i = 0; i < daftarMobil.size(); i++) {
            if (daftarMobil[i].getPlat() == platDicari) {
                ditemukan = true;
                
                int jam, menit, detik;
                hitungDurasi(daftarMobil[i].getWaktuMasuk(), jam, menit, detik);
                
                int totalDetik = (jam * 3600) + (menit * 60) + detik;
                int biayaParkir = totalDetik * 2; // [Sudah direvisi ke Rp120/menit]

                cout << "\nB I A Y A  P A R K I R : Rp" << biayaParkir << "\n";
                cout << "========================================================================\n";

                RiwayatParkir riwayatSelesai;
                riwayatSelesai.platMobil = daftarMobil[i].getPlat();
                riwayatSelesai.merkMobil = daftarMobil[i].getMerk();
                riwayatSelesai.warnaMobil = daftarMobil[i].getWarna();
                riwayatSelesai.jam = jam;
                riwayatSelesai.menit = menit;
                riwayatSelesai.detik = detik;
                riwayatSelesai.totalBiaya = biayaParkir;
                
                daftarRiwayat.push_back(riwayatSelesai); 

                daftarMobil.erase(daftarMobil.begin() + i); 
                break;
            }
        }

        if (!ditemukan) {
            cout << "PLAT TIDAK DITEMUKAN !\n\n";
        }
    }
}

void tampilkanRiwayatKeluar(const vector<RiwayatParkir>& daftarRiwayat) {
    cout << "\n--- DATA KENDARAAN YANG TELAH KELUAR (RIWAYAT) ---\n";
    cout << "========================================================================\n";
    
    if (daftarRiwayat.empty()) {
        cout << "Belum ada kendaraan yang keluar / melakukan pembayaran.\n";
        cout << "========================================================================\n";
        return;
    }

    for (size_t i = 0; i < daftarRiwayat.size(); i++) {
        cout << i + 1 << ". Plat Mobil : " << daftarRiwayat[i].platMobil << "\n";
        cout << "   Merk/Warna : " << daftarRiwayat[i].merkMobil << " (" << daftarRiwayat[i].warnaMobil << ")\n";
        cout << "   Lama Parkir: " << daftarRiwayat[i].jam << " jam " << daftarRiwayat[i].menit << " menit " << daftarRiwayat[i].detik << " detik\n";
        cout << "   Total Biaya: Rp" << daftarRiwayat[i].totalBiaya << "\n";
        cout << "------------------------------------------------------------------------\n";
    }
}