#include <iostream>
#include <string>
using namespace std;

int main() {
    string nomor;
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor;

    int panjang = nomor.length();
    bool valid_format;
    string tipe = "";

    if (panjang == 14 && nomor[0] == '6' && nomor[1] == '5') {
        tipe = "NUSANTARA";
        valid_format = true;
    } else if (panjang == 16 && nomor[0] == '7' && (nomor[1] == '7' || nomor[1] == '8')) {
        tipe = "GARUDA";
        valid_format = true;
    } else if (panjang == 15 && nomor[0] == '9' && nomor[1] == '1') {
        tipe = "MERDEKA";
        valid_format = true;
    }  else {
        tipe = "TIDAK DIKENAL";
        valid_format = false; }

    if (valid_format) {
        cout << "Tipe kartu: " << tipe << endl;
        int total = 0;
        for (int i = 0; i < panjang; i++) {
            int digit = nomor[panjang - 1 - i] - '0';
            if (i % 2 == 1) {   
                digit = digit * 2;
                if (digit > 9) {
                    digit = digit / 10 + digit % 10;
                }
            }
            total = total + digit;
        } if (total % 10 == 0) {
            cout << "Nomor kartu VALID." << endl;
        } else {
            cout << "Nomor kartu TIDAK VALID." << endl;
        }
    } else {
        cout << "Tipe kartu: "<< tipe << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;
    }

    return 0;
}

