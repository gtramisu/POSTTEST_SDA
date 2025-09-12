#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[4];

    cout << "Input data 4 mahasiswa\n";
    for (int i = 0; i < 4; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    cout << "\n+------------+------------+--------+\n";
    cout << "| Nama       | NIM        | IPK    |\n";
    cout << "+------------+------------+--------+\n";

    for (int i = 0; i < 4; i++) {
        cout << "| " << left << setw(10) << mhs[i].nama
             << "| " << setw(10) << mhs[i].nim
             << "| " << setw(6) << mhs[i].ipk << "|\n";
    }

    cout << "+------------+------------+--------+\n";

    return 0;
}