#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int m[3][3];

    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Baris ke-" << i + 1 << " : ";
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }

    cout << "\n+-----+-----+-----+\n";
    cout << "|   Matriks 3x3  |\n";
    cout << "+-----+-----+-----+\n";
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << m[i][j] << " |";
        }
        cout << "\n";
    }
    cout << "+-----+-----+-----+\n";

    int jumlah = 0;
    for (int j = 0; j < 3; j++) jumlah += m[1][j];

    cout << "Jumlah elemen baris ke-2 = " << jumlah << endl;

    return 0;
}