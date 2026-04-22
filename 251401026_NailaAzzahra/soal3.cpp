#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    bool valid = true;
    if (kode.length() != 8) {
        valid = false;
    } else {
        for (int i = 0; i < 8; i++) {
            if (kode[i] < '0' || kode[i] > '9') {
                valid = false;
            }
        }
    }

    if (valid) {
        int kode_hari      = (kode[0] - '0') * 10 + (kode[1] - '0');
        int kode_loyalitas = (kode[2] - '0') * 10 + (kode[3] - '0');
        int jumlah_unit    = (kode[4]-'0')*1000 + (kode[5]-'0')*100
                           + (kode[6]-'0')*10   + (kode[7]-'0');

        if (kode_hari < 1 || kode_hari > 3)         valid = false;
        if (kode_loyalitas < 1 || kode_loyalitas > 3) valid = false;

        if (!valid) {
            cout << "Kode transaksi tidak valid!" << endl;
        } else {

            string jenis_hari;
            if (kode_hari == 1)      jenis_hari = "Hari Kerja";
            else if (kode_hari == 2) jenis_hari = "Akhir Pekan";
            else                     jenis_hari = "Hari Libur Nasional";
    
            string jenis_pelanggan;
            if (kode_loyalitas == 1)      jenis_pelanggan = "Biasa";
            else if (kode_loyalitas == 2) jenis_pelanggan = "Silver";
            else                          jenis_pelanggan = "Gold";
            
            int poin_per_unit = 0;
            if (kode_hari == 1) {           
                if (kode_loyalitas == 1)      poin_per_unit = 1;
                else if (kode_loyalitas == 2) poin_per_unit = 2;
                else                          poin_per_unit = 3;
            } else if (kode_hari == 2) {    
                if (kode_loyalitas == 1)      poin_per_unit = 2;
                else if (kode_loyalitas == 2) poin_per_unit = 3;
                else                          poin_per_unit = 5;
            } else {
                if (kode_loyalitas == 1)      poin_per_unit = 3;
                else if (kode_loyalitas == 2) poin_per_unit = 5;
                else                          poin_per_unit = 7;
            }

            long long total_poin    = (long long)jumlah_unit * poin_per_unit;
            long long jumlah_belanja = (long long)jumlah_unit * 100000;

            cout << "Jenis Hari: "       << jenis_hari << endl;
            cout << "Jenis Pelanggan: "  << jenis_pelanggan << endl;
            cout << "Jumlah Belanja: Rp "<< jumlah_belanja << endl;
            cout << "Total Poin: "       << total_poin << endl;
        }
    } else {
        cout << "Kode transaksi tidak valid!" << endl;
    }

    return 0;
}

// validasi dilakukan dua tahap: cek panjang & semua digit dulu, lalu cek isi kodenya
// loop cek karakter pakai range ASCII '0'-'9' biar bisa deteksi huruf atau simbol
// kode dipotong manual pakai - '0' karena inputnya string bukan int
// if bertingkat dipakai untuk kombinasi hari x pelanggan supaya tidak perlu 9 kondisi terpisah
// long long dipakai untuk antisipasi hasil perkalian yang besar
