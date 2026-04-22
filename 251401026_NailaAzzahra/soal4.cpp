#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int poin_a   = 0, poin_b   = 0;
    int streak_a = 0, streak_b = 0;

    for (int i = 0; i < n; i++) {
        char hasil = s[i];

        if (hasil == 'A') {
            poin_a   = poin_a + 3;
            streak_a = streak_a + 1;
            streak_b = 0;
            if (streak_a % 3 == 0) {
                poin_a = poin_a + 2;
            }
        } else if (hasil == 'B') {
            poin_b   = poin_b + 3;
            streak_b = streak_b + 1;
            streak_a = 0;
            if (streak_b % 3 == 0) {
                poin_b = poin_b + 2;
            }
        } else if (hasil == 'C') {
            poin_a   = poin_a + 1;
            poin_b   = poin_b + 1;
            streak_a = 0;
            streak_b = 0;
        }
    }

    cout << "Poin A: " << poin_a << endl;
    cout << "Poin B: " << poin_b << endl;

    if (poin_a > poin_b) {
        cout << "Pemenangnya adalah pemain A" << endl;
    } else if (poin_b > poin_a) {
        cout << "Pemenangnya adalah pemain B" << endl;
    } else {
        cout << "Hasil pertandingan Seri!" << endl;
    }

    return 0;
}

