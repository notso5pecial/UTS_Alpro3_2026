#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode, jam_keluar_str, jenis;
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jam_keluar_str;
    
    int kode_kendaraan = (kode[0] - '0') * 10 + (kode[1] - '0');
    int jam_masuk      = (kode[2] - '0') * 10 + (kode[3] - '0');
    int menit_masuk    = (kode[4] - '0') * 10 + (kode[5] - '0');
    string lokasi_parkir = kode.substr(6, 4);

    int jam_keluar   = (jam_keluar_str[0] - '0') * 10 + (jam_keluar_str[1] - '0');
    int menit_keluar = (jam_keluar_str[2] - '0') * 10 + (jam_keluar_str[3] - '0');
    
    if (kode_kendaraan == 10) {
        jenis = "Mobil";
    } else if (kode_kendaraan == 20) {
        jenis = "Motor";
    } else if (kode_kendaraan == 30) {
        jenis = "Bus";
    } else {
        jenis = "Tidak Dikenal";
    }

    int total_menit_masuk  = jam_masuk * 60 + menit_masuk;
    int total_menit_keluar = jam_keluar * 60 + menit_keluar;
    int selisih_menit      = total_menit_keluar - total_menit_masuk;
    
    if (selisih_menit < 0) {
        selisih_menit = selisih_menit + 24 * 60;
    }

    int durasi_jam = selisih_menit / 60;
    if (selisih_menit % 60 > 0) {
        durasi_jam = durasi_jam + 1;
    }

    int tarif_pertama = 0, tarif_berikutnya = 0;
    if (jenis == "Mobil") {
        tarif_pertama    = 5000;
        tarif_berikutnya = 3000;
    } else if (jenis == "Motor") {
        tarif_pertama    = 3000;
        tarif_berikutnya = 2000;
    } else if (jenis == "Bus") {
        tarif_pertama    = 10000;
        tarif_berikutnya = 7000;
    }

    int total_biaya = 0;
    if (durasi_jam <= 1) {
        total_biaya = tarif_pertama;
    } else {
        total_biaya = tarif_pertama + (durasi_jam - 1) * tarif_berikutnya;
    }

    string jm = (jam_masuk < 10 ? "0" : "") + to_string(jam_masuk);
    string mm = (menit_masuk < 10 ? "0" : "") + to_string(menit_masuk);
    string jk = (jam_keluar < 10 ? "0" : "") + to_string(jam_keluar);
    string mk = (menit_keluar < 10 ? "0" : "") + to_string(menit_keluar);

    cout << endl;
    cout << "--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan: " << jenis << endl;
    cout << "Waktu masuk: "     << jm << ":" << mm << endl;
    cout << "Waktu keluar: "    << jk << ":" << mk << endl;
    cout << "Durasi parkir: "   << durasi_jam << " jam" << endl;
    cout << "Lokasi parkir: "   << lokasi_parkir << endl;
    cout << "Total biaya: Rp "  << total_biaya << endl;

    return 0;
}
